#include "tableswidget.h"
#include "ui_tableswidget.h"
#include <QDebug>

TablesWidget::TablesWidget(QWidget *parent, QSqlDatabase *activeDB) :
    QWidget(parent),
    ui(new Ui::TablesWidget)
{
    ui->setupUi(this);
    qdb = activeDB;

    ui->tableTree->setHeaderLabels(QStringList(getDBName()));
    QFont font;
    font.setBold(true);
    ui->tableTree->setFont(font);

    QStringList tablesNames = getDBTables();
    for (int i = 0; i < tablesNames.length();i++){
        QTreeWidgetItem *table = new  QTreeWidgetItem(ui->tableTree);
        table->setText(0, tablesNames.at(i));
    }
    tree = ui->tableTree;


}

TablesWidget::~TablesWidget()
{
    delete ui;
}
QStringList TablesWidget::getDBTables(){


    QStringList tablesNames = qdb->tables();

    return tablesNames;

}

QString TablesWidget::getDBName(){

    return qdb->databaseName();
}

QTreeWidget *TablesWidget::getTree(){


    return tree;
}
