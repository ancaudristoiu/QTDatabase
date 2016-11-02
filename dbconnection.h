#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>
#include <QtCore>
#include <QtSql>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QMessageBox>


class DbConnection : public QObject
{
    Q_OBJECT
public:
    explicit DbConnection(QObject *parent = 0);
    QSqlDatabase *connect(QString driverName, QString hostName, QString dbName, QString userName, QString userPassword, int port);
    ~DbConnection();

private:

signals:

public slots:

};

#endif // DBCONNECTION_H
