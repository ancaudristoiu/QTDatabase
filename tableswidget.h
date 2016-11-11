#ifndef TABLESWIDGET_H
#define TABLESWIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QTreeWidget>

namespace Ui {
class TablesWidget;
}

class TablesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TablesWidget(QWidget *parent = 0, QSqlDatabase *activeDB=NULL);
    ~TablesWidget();
    QStringList getDBTables();
    QString getDBName();
    QTreeWidget *getTree();


private:
    Ui::TablesWidget *ui;
    QSqlDatabase *qdb;
    QTreeWidget *tree;
};

#endif // TABLESWIDGET_H
