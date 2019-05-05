#include "editteacherdialog.h"
#include "ui_editteacherdialog.h"

editteacherdialog::editteacherdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editteacherdialog)
{
    ui->setupUi(this);
}

editteacherdialog::~editteacherdialog()
{
    delete ui;
}

void editteacherdialog::on_pushButton_showAllStudent_clicked()
{
    showtea = new showteacherdialog();
    showtea->show();
}

void editteacherdialog::on_pushButton_search_clicked()
{
    if(ui->lineEdit->text() != ""){
        QString teacode ;
        QString currid;
        QString fname ;
        QString lname ;
        QString national ;
        QString degree ;
        QString gender ;
        QString tcode;
        QSqlQuery qry2 ;
        QSqlQuery qry1 ;


        teacode = ui->lineEdit->text();

        qry1.prepare("select ID from Student.dbo.tblTeacher where TeacherCode = :teacode");
        qry1.bindValue(":teacode" , teacode);
        qry1.exec();
        while(qry1.next()){
            currid = qry1.value(0).toString();
        }

        qry2.prepare("Select p.FirstName , p.LastName , p.NationalCode , p.Gender , t.EducationDegree , t.TeacherCode from Student.dbo.tblPerson as p , Student.dbo.tblTeacher as t where p.ID = t.ID and p.ID = :currid");
        qry2.bindValue(":currid" , currid);
        qry2.exec();
        while(qry2.next()){
            fname = qry2.value(0).toString();
            lname = qry2.value(1).toString();
            national = qry2.value(2).toString();
            gender = qry2.value(3).toString();
            degree = qry2.value(4).toString();
            tcode = qry2.value(5).toString();
        }
        ui->lineEdit_name->setText(fname);
        ui->lineEdit_lastname->setText(lname);
        ui->lineEdit_nationalcode->setText(national);
        ui->lineEdit_degree->setText(degree);
        ui->label_stuCode->setText(tcode);

        if(gender=="True"){
            ui->comboBox_gender->setCurrentText("مرد");
        }
        else {
            ui->comboBox_gender->setCurrentText("زن");
        }

    }
    else {
        QMessageBox::information(this , "خطا" , "لطفا فیلد خالی رو پر کنید .");
    }
}

void editteacherdialog::on_pushButton_back_clicked()
{
    this->close();
}

void editteacherdialog::on_pushButton_apply_clicked()
{
    QString fname;
    QString lname;
    QString ncode;
    QString degree;
    QString gender;
    QString code ;
    QString id ;
    fname = ui->lineEdit_name->text();
    lname = ui->lineEdit_lastname->text();
    ncode = ui->lineEdit_nationalcode->text();
    degree = ui->lineEdit_degree->text();
    code = ui->label_stuCode->text();
    gender = ui->comboBox_gender->currentText();
    if(gender == "مرد"){
        gender = "True" ;
    }
    else {
        gender = "False";
    }

    QSqlQuery qry ;
    QSqlQuery qry1 , qry2 ;
    qry.prepare("UPDATE Student.dbo.tblTeacher set EducationDegree = :degree where TeacherCode = :code");
    qry.bindValue(":code" , code);
    qry.bindValue(":degree" , degree);
    qry.exec();

    qry2.prepare("Select ID from Student.dbo.tblTeacher where TeacherCode = :code");
    qry2.bindValue(":code" , code);
    qry2.exec();
    while(qry2.next()){
        id = qry2.value(0).toString();
    }

    qry1.prepare("UPDATE Student.dbo.tblPerson set FirstName = :fname , LastName = :lname , NationalCode = :ncode , Gender = :gender where ID = :id");
    qry1.bindValue(":id" , id);
    qry1.bindValue(":fname" , fname);
    qry1.bindValue(":lname" , lname);
    qry1.bindValue(":ncode" , ncode);
    qry1.bindValue(":gender" , gender);
    qry1.exec();
    QMessageBox::information(this , "done" , "مشخصات استاد با موفقیت تغییر کرد");
}
