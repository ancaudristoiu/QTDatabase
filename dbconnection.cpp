#include "dbconnection.h"

DbConnection::DbConnection(QObject *parent) : QObject(parent)
{

}

QSqlDatabase* DbConnection::connect(QString driverName, QString hostName, QString dbName, QString userName, QString userPassword, int port){

    QSqlDatabase *db = new QSqlDatabase(QSqlDatabase::addDatabase(driverName));
    db->setHostName(hostName);
    db->setDatabaseName(dbName);
    db->setUserName(userName);
    db->setPassword(userPassword);
    db->setPort(port);

    if (db->open()){
        qDebug() << "Database successfully connected!" << endl;
        return db;
    }
    else
    {
        qDebug() << "Database does not successfully connected!" << endl;

        return NULL;

    }
}
DbConnection::~DbConnection(){

    qDebug()<< "Destructor called";

}
