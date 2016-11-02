#ifndef DBDIALOG_H
#define DBDIALOG_H

#include <QDialog>

namespace Ui {
class DBDialog;
}

class DBDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DBDialog(QWidget *parent = 0);
    ~DBDialog();

private:
    Ui::DBDialog *ui;
};

#endif // DBDIALOG_H
