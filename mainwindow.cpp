#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DBDialog *dbDialog = new DBDialog(this);
    dbDialog->exec();

    DbConnection *dbConn = new DbConnection(this);

    QSqlDatabase *qdb = dbConn->connect(dbDialog->driverName(),dbDialog->hostName(),dbDialog->databaseName(),dbDialog->userName(), dbDialog->passwordName(),dbDialog->port());
    if (qdb == NULL){

        QMessageBox::information(this, "Connection to database failed", "Insert correct information");
    }



}

MainWindow::~MainWindow()
{
    delete ui;
}
