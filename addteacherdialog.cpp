#include "addteacherdialog.h"
#include "ui_addteacherdialog.h"

addteacherdialog::addteacherdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addteacherdialog)
{
    ui->setupUi(this);
//    QStringList year[20];
//    for(int i = 0 ; i<60 ; i++)
//        year[i] = i+1330 ;
//    ui->comboBox->addItems(year);
    for(int i = 1330 ; i<1386 ; i++){
        ui->comboBox_year->addItem(QString::number(i));
    }
}

addteacherdialog::~addteacherdialog()
{
    delete ui;
}

void addteacherdialog::on_pushButton_clicked()
{
    if(ui->lineEdit_name->text()!="" &&ui->lineEdit_degree->text()!="" && ui->lineEdit_family->text()!="" &&ui->lineEdit_Nationalcode->text()!=""){
        QSqlQuery qry1;
        QSqlQuery qry2;
        QSqlQuery qry3;

        QString strName;
        QString strLastname;
        QString strNationalcode;
        QString strDegree;
        QVariant correntID;
        QDate birthDate;
        bool blGender;

        strName = ui->lineEdit_name->text();
        strLastname = ui->lineEdit_family->text();
        strNationalcode = ui->lineEdit_Nationalcode->text();
        strDegree = ui->lineEdit_degree->text();
        birthDate.setDate(ui->comboBox_year->currentText().toInt(), ui->comboBox_month->currentText().toInt(), ui->comboBox_day->currentText().toInt());

        if(ui->radioButton_male->isChecked()){
            blGender =  true;
        }
        else if(ui->radioButton_female->isChecked()){
            blGender = false;
        }


        qry1.prepare("Insert Into Student.dbo.tblPerson \
                     (FirstName \
                     ,LastName \
                     ,Nationalcode \
                     ,Gender) \
                     Values(:name , :lastname , :nationalcode , :gender)"); //  , :birthdate  ,BirthDate
                    qry1.bindValue(":name", strName);
                    qry1.bindValue(":lastname", strLastname);
                    qry1.bindValue(":nationalcode", strNationalcode);
                    qry1.bindValue(":gender", blGender );
                   // qry1.bindValue(":birthdate", birthDate);
                    qry1.exec();

        correntID = qry3.lastInsertId().toString();

        qry2.prepare("Insert Into Student.dbo.tblTeacher \
                     (ID \
                     ,EducationDegree \
                     ,Password) \
                     Values(:id , :degree , :password)");
                    qry2.bindValue(":id" , correntID);
                    qry2.bindValue(":degree", strDegree);
                    qry2.bindValue(":password", strNationalcode);
                    qry2.exec();

        QMessageBox::information(this, "OK", "استاد اضافه شد.");
    }
    else {
        QMessageBox::information(this , "عملیات ناموفق" , "تمامی موارد بالا را پر کنید");
    }
}

void addteacherdialog::on_pushButton_2_clicked()
{
    showteadialog = new showteacherdialog();
    showteadialog->show();
}

void addteacherdialog::on_pushButton_3_clicked()
{
    this->close();
}
