#include "studentmaindialog.h"
#include "ui_studentmaindialog.h"

studentmaindialog::studentmaindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentmaindialog)
{
    ui->setupUi(this);
}

studentmaindialog::~studentmaindialog()
{
    delete ui;
}

void studentmaindialog::on_pushButton_exit_clicked()
{
    this->close();
}
