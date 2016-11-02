#include "dbdialog.h"
#include "ui_dbdialog.h"
#include "dbconnection.h"

DBDialog::DBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBDialog)
{
    ui->setupUi(this);
    QStringList driverList = QSqlDatabase::drivers();
    ui->comboDriver->addItems(driverList);
}

QString DBDialog::driverName() const{
    return ui->comboDriver->currentText();

}
QString DBDialog::databaseName() const{
    return ui->editDatabase->text();

}
QString DBDialog::userName() const{
    return ui->editUsername->text();

}
QString DBDialog::passwordName() const{
    return ui->editPassword->text();

}
QString DBDialog::hostName() const{
    return ui->editHostname->text();
}
int DBDialog::port() const{
    return ui->editPort->text().toInt();

}

DBDialog::~DBDialog()
{
    delete ui;
}


void DBDialog::on_okButton_clicked()
{
    if(ui->comboDriver->currentText().isEmpty()){
        QMessageBox::information(this, "No database driver selected", "Please select a database driver!");

    }
    else{
        accept();
    }
}

void DBDialog::on_cancelButton_clicked()
{
    reject();
}
