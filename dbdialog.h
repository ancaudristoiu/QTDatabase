#ifndef DBDIALOG_H
#define DBDIALOG_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class DBDialog;
}

class DBDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DBDialog(QWidget *parent = 0);
    ~DBDialog();
    QString driverName() const;
    QString databaseName() const;
    QString userName() const;
    QString passwordName() const;
    QString hostName() const;
    int port() const;


private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::DBDialog *ui;
};

#endif // DBDIALOG_H
