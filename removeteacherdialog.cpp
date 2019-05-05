#include "removeteacherdialog.h"
#include "ui_removeteacherdialog.h"

removeteacherdialog::removeteacherdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeteacherdialog)
{
    ui->setupUi(this);
}

removeteacherdialog::~removeteacherdialog()
{
    delete ui;
}

void removeteacherdialog::on_pushButton_showAllStu_clicked()
{
    showteadialog = new showteacherdialog();
    showteadialog->show();
}

void removeteacherdialog::on_pushButton_remove_clicked()
{
    QSqlQuery qry1;
    QSqlQuery qry2;
    QSqlQuery qry3;

    QString stuCode;
    QString currID;
    QString strQry;

    if(!(ui->label_stuCode->text().isEmpty())){
        stuCode = ui->label_stuCode->text();

        strQry = "SELECT ID FROM Student.dbo.tblTeacher WHERE Student.dbo.tblTeacher.TeacherCode = " + stuCode;

        qry1.exec(strQry);
        while(qry1.next()){
            currID = qry1.value(0).toString();
        }

        qry2.prepare("Delete From Student.dbo.tblTeacher\
                     Where Student.dbo.tblTeacher.TeacherCode = :stucode");
        qry2.bindValue(":stucode", stuCode);
        if(qry2.exec()){
            qry3.prepare("Delete From Student.dbo.tblPerson \
                         Where Student.dbo.tblPerson.ID = :id");
            qry3.bindValue(":id", currID);
            if(qry3.exec()){
                QMessageBox::information(this, "OK", "استاد مورد نظر حذف شد.");
            }
            else{
                QMessageBox::warning(this,"Error", "There is Something Wrong In Database");
            }
        }
        else
        {
            QMessageBox::warning(this,"Error", "There is Something Wrong In Database");
        }
    }
    else{
        QMessageBox::warning(this, "Warning", "لطفا ابتدا یک کد کارمندی وارد کنید.");
    }
}

void removeteacherdialog::on_pushButton_search_clicked()
{
    QSqlQuery qry1;
    QSqlQuery qry2;
    QSqlQuery qry3;

    QString strStuCode;
    QString currID;
    QString name;
    QString nationalCode;
    QString stuCode;

    stuCode = ui->lineEdit_stuCode->text();

    qry1.prepare("Select ID,TeacherCode From Student.dbo.tblTeacher Where Student.dbo.tblTeacher.TeacherCode = :stuCode");
    qry1.bindValue(":stuCode", stuCode);
    qry1.exec();
    while(qry1.next()){
        currID = qry1.value(0).toString();
        strStuCode = qry1.value(1).toString();
    }

    qry2.prepare("Select FirstName, LastName, NationalCode \
                  From Student.dbo.tblPerson \
                  Where tblPerson.ID = :id");
            qry2.bindValue(":id", currID);
            qry2.exec();
    while(qry2.next()){
        name = qry2.value(0).toString() + " " +qry2.value(1).toString();
        nationalCode = qry2.value(2).toString();
    }

    ui->label_name->setText(name);
    ui->label_nationalCode->setText(nationalCode);
    ui->label_fathersName->setText("");
    ui->label_stuCode->setText(strStuCode);
}

void removeteacherdialog::on_pushButton_back_clicked()
{
    this->close();
}
