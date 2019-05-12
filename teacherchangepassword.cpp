#include "teacherchangepassword.h"
#include "ui_teacherchangepassword.h"

teacherchangepassword::teacherchangepassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherchangepassword)
{
    ui->setupUi(this);
}

teacherchangepassword::~teacherchangepassword()
{
    delete ui;
}

void teacherchangepassword::on_pushButton_2_clicked()
{
    this->close();
}

void teacherchangepassword::on_pushButton_clicked()
{
    QString newpass = ui->label_newPass->text();
    QString newpass2 = ui->label_repeatNewPass->text();
    if(newpass != newpass2){
        QMessageBox::warning(this, "warning", "اطلاعات را صحیح وارد کنید.");
        ui->lineEdit_repeatNewPass->text().clear();
    }
    else {
    }

}
