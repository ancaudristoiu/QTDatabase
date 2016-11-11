#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectDBDialog();
    tableswidget = new TablesWidget(this, qdb);
    ui->docWidget->setWidget(tableswidget);
    tableswidget->getDBTables();
    QTreeWidget *tree =  tableswidget->getTree();

    connect(tree, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(displayTableContent(QTreeWidgetItem *)));

    QMenu *contextMenu = new QMenu(tree);
    tree->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *showSchemaAction = new QAction("Show schema", contextMenu);
    tree->addAction(showSchemaAction);
    connect(showSchemaAction, SIGNAL(triggered(bool)), this, SLOT(on_actionShowSchema()));



}

void MainWindow::connectDBDialog(){

    DBDialog *dbDialog = new DBDialog(this);
    dbDialog->exec();

    DbConnection *dbConn = new DbConnection(this);

    qdb = dbConn->connect(dbDialog->driverName(),dbDialog->hostName(),dbDialog->databaseName(),dbDialog->userName(), dbDialog->passwordName(),dbDialog->port());
    if (qdb == NULL){

        QMessageBox::information(this, "Connection to database failed", "Insert correct information");
    }
}

void MainWindow::displayTableContent(QTreeWidgetItem *current){
    QString tableName =  current->text(0);
    QTableView *tableView = ui->tableContent;
    QSqlTableModel *tableModel = new QSqlTableModel(this, *qdb) ;
    tableModel->setEditStrategy(QSqlTableModel::OnRowChange);
    tableModel->setTable(tableName);
    tableModel->select();
    tableView->setModel(tableModel);
    tableView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed);

    tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(customMenuRequested(QPoint)));
}
void MainWindow::customMenuRequested(QPoint pos){

    QTableView *tableView = ui->tableContent;
    QModelIndex index = tableView->indexAt(pos);

    QMenu *menu = new QMenu(this);
    QAction *actionInsert = new QAction("Insert Row", this);
    menu->addAction(actionInsert);
    QAction *actionDelete = new QAction("Delete Row", this);
    menu->addAction(actionDelete);
    QAction *actionUpdate = new QAction("Update Row", this);
    menu->addAction(actionUpdate);

    menu->popup(tableView->viewport()->mapToGlobal(pos));
    connect(actionInsert, SIGNAL(triggered(bool)), this, SLOT(on_actionInsertRow()));
    connect(actionDelete, SIGNAL(triggered(bool)), this, SLOT(on_actionDeleteRow()));
    connect(actionUpdate, SIGNAL(triggered(bool)), this, SLOT(on_actionUpdateRow()));
}


void MainWindow::displayQueryContent(){
    QString query =  ui->queryEdit->toPlainText();
    QTableView *tableView = ui->tableContent;
    QSqlQueryModel *queryModel = new QSqlTableModel ;
    queryModel->setQuery(query, *qdb);
    tableView->setModel(queryModel);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void MainWindow::on_actionInsertRow(){
    QTableView *tableView = ui->tableContent;
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(tableView->model());
    if (!model)
        return;

    QModelIndex insertIndex = tableView->currentIndex();
    int row = insertIndex.row() == -1 ? 0 : insertIndex.row();
    model->insertRow(row);
    insertIndex = model->index(row, 0);
    tableView->setCurrentIndex(insertIndex);
    tableView->edit(insertIndex);
}
void MainWindow::on_actionUpdateRow(){
    QTableView *tableView = ui->tableContent;
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(tableView->model());
    if (!model)
        return;

    QModelIndex updateIndex = tableView->currentIndex();

    int row = updateIndex.row() == -1 ? 0 : updateIndex.row();
    QSqlRecord record = model->record(row);
    model->setRecord(row, record);
  /*  updateIndex = model->index(row, 0);
    tableView->setCurrentIndex(updateIndex);
    tableView->edit(updateIndex);*/

}

void MainWindow::on_actionDeleteRow(){
    QTableView *tableView = ui->tableContent;
    QSqlTableModel *model = qobject_cast<QSqlTableModel *>(tableView->model());
    if (!model)
        return;

    QModelIndexList currentSelection = tableView->selectionModel()->selectedIndexes();
    for (int i = 0; i < currentSelection.count(); ++i) {
        if (currentSelection.at(i).column() != 0)
            continue;
        model->removeRow(currentSelection.at(i).row());
    }
    model->submitAll();

}

 void MainWindow::on_actionShowSchema(){

    qDebug()<< "Show Schema ";

 }
void MainWindow::on_actionAdd_Connection_triggered()
{
   connectDBDialog();

}

void MainWindow::on_actionAbout_triggered()
{

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    displayQueryContent();
}

void MainWindow::on_pushButton_clicked()
{
    ui->queryEdit->clear();
}

