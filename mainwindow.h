#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include <QAction>
#include <QtSql>
#include <QtWidgets>
#include "dbconnection.h"
#include "dbdialog.h"
#include "tableswidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void connectDBDialog();


private slots:
    void displayTableContent(QTreeWidgetItem*);
    void displayQueryContent();
    void customMenuRequested(QPoint pos);
    void on_actionInsertRow();
    void on_actionDeleteRow();
    void on_actionUpdateRow();
    void on_actionShowSchema();
    void on_actionAdd_Connection_triggered();
    void on_actionAbout_triggered();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;
    TablesWidget *tableswidget;
    QSqlDatabase *qdb;
};

#endif // MAINWINDOW_H
