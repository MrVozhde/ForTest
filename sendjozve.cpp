#include "sendjozve.h"
#include "ui_sendjozve.h"

sendjozve::sendjozve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendjozve)
{
    ui->setupUi(this);
}

sendjozve::~sendjozve()
{
    delete ui;
}

void sendjozve::on_pushButton_2_clicked()
{
    this->close();
}

void sendjozve::on_pushButton_clicked()
{
    QString id_erae = teacherchangepassword::lessoncode;
    QString jozve = ui->lineEdit_jozve->text();
    QSqlQuery qry;
    qry.prepare("UPDATE Student.dbo.tblErae Set jozve = :jozve where ID = :id_erae ");
    qry.bindValue(":jozve" , jozve);
    qry.bindValue(":id_erae" , id_erae);
    if(qry.exec()){
        QMessageBox::information(this , "Done" , "دیتابیس به روز رسانی شد");
    }
    else {
        QMessageBox::warning(this , "Error" , "به روزرسانی دیتابیس با مشکل روبرو شد");
    }
}
