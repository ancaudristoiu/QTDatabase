#include "dbdialog.h"
#include "ui_dbdialog.h"

DBDialog::DBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBDialog)
{
    ui->setupUi(this);
}

DBDialog::~DBDialog()
{
    delete ui;
}
