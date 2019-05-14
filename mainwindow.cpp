#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <employeemaindialog.h>
#include <teachermaindialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("myDSN32");
    db.setHostName("localhost");
    db.open();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

QString EmployeeChangePasswordDialog::strUser;
QString teacherchangepassword::username ;

void MainWindow::on_pushButton_manager_clicked()
{
    QString strUsername = ui->lineEdit_username->text() ;
    QString strPassword = ui->lineEdit_password->text();



    QSqlQuery qry;

    qry.prepare("Select Password From Student.dbo.tblEmployee \
                 Where tblEmployee.EmployeeCode = :username");
                qry.bindValue(":username", strUsername);
                qry.exec();
    if(qry.next()){
        if(strPassword == qry.value(0).toString()){
            EmployeeChangePasswordDialog::strUser = strUsername;
            emploMainDialog = new EmployeeMainDialog(this);
            emploMainDialog->show();
        }
    }else{
        QMessageBox::warning(this, "warning", "رمز عبور وارد شده صحیح نمیباشد.");
    }
}

void MainWindow::on_pushButton_teacher_clicked()
{
    QString strUsername = ui->lineEdit_username->text();
    QString strPassword = ui->lineEdit_password->text();


    QSqlQuery qry;

    qry.prepare("Select Password From Student.dbo.tblTeacher \
                 Where tblTeacher.TeacherCode = :teachercode");
                qry.bindValue(":teachercode", strUsername);
                qry.exec();
    if(qry.next()){
        if(strPassword == qry.value(0).toString()){
            teacherchangepassword::username = strUsername;
            teamaindialog = new teachermaindialog(this);
            teamaindialog->show();
        }

    }else{
        QMessageBox::warning(this, "warning", "رمز عبور وارد شده صحیح نمیباشد.");
    }
}

void MainWindow::on_pushButton_stu_clicked()
{
    QString strUsername = ui->lineEdit_username->text();
    QString strPassword = ui->lineEdit_password->text();

    QSqlQuery qry;

    qry.prepare("Select Password From Student.dbo.tblStudent \
                 Where tblStudent.StudentCode = :stucode");
                qry.bindValue(":stucode", strUsername);
                qry.exec();
    if(qry.next()){
        stumaindialog = new studentmaindialog(this);
        stumaindialog->show();
    }else{
        QMessageBox::warning(this, "warning", "رمز عبور وارد شده صحیح نمیباشد.");
    }
}
