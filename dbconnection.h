#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <QObject>

class DbConnection : public QObject
{
    Q_OBJECT
public:
    explicit DbConnection(QObject *parent = 0);

signals:

public slots:
};

#endif // DBCONNECTION_H