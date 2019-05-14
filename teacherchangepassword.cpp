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
//    QString newpass = ui->label_newPass->text();
//    QString newpass2 = ui->label_repeatNewPass->text();

//    if( newpass != newpass2 ){
//        QMessageBox::warning(this, "warning", "اطلاعات را صحیح وارد کنید.");
//        ui->lineEdit_repeatNewPass->text().clear();
//    }
//    else {
//        QString teacode = username ;
//        QSqlQuery qry ;
//        qry.prepare("Update [Student].[dbo].[tblTeacher] set Password = :newpass where TeacherCode = :teacode");
//        qry.bindValue(":teacode" , teacode);
//        qry.bindValue(":newpass" , newpass);
//        qry.exec();
//        QMessageBox::information(this , "Done" , "رمز عبور با موفقیت تغییر کرد");
//    }
    QString newPass = ui->lineEdit_newPass->text();
    QString repNewPass = ui->lineEdit_repeatNewPass->text();

    if(newPass != repNewPass){
        QMessageBox::warning(this, "warning", "اطلاعات را صحیح وارد کنید.");
        ui->lineEdit_repeatNewPass->text().clear();
    }else{
        QSqlQuery qry;
        qry.prepare("Update Student.dbo.tblTeacher \
                     Set Password = :pass \
                     Where TeacherCode = :empcode");
                qry.bindValue(":pass", newPass);
                qry.bindValue(":empcode", username);
                qry.exec();

        QMessageBox::information(this, "OK", "رمز عبور شما با موفقیت تغییر کرد.");
    }

}
