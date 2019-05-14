#include "teachermaindialog.h"
#include "ui_teachermaindialog.h"

teachermaindialog::teachermaindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teachermaindialog)
{
    ui->setupUi(this);
    this->model = new QSqlQueryModel();
    model->setQuery("SELECT   Student.dbo.tblLesson.Title as 'نام درس', Student.dbo.tblErae.ID as 'مشخصه', Student.dbo.tblLesson.LessonCode as 'کد درس', Student.dbo.tblLesson.Type as 'نوع', Student.dbo.tblLesson.TedadVahedas 'تعداد واحد', Student.dbo.tblErae.DaysOfWeek as 'روزهای برگزاری' , Student.dbo.tblErae.TimeOfClass as 'زمان کلاس' , Student.dbo.tblErae.jozve as 'جزوه'\
                    FROM      dbo.tblEntekhabVahed INNER JOIN \
                              dbo.tblErae ON dbo.tblEntekhabVahed.ID_Erae = dbo.tblErae.ID INNER JOIN \
                              dbo.tblLesson ON dbo.tblErae.ID_Lesson = dbo.tblLesson.ID");
            ui->tableView->setModel(model);


    QString user = teacherchangepassword::username;
    QString fullname ;
    QSqlQuery qry;
    qry.prepare("select FirstName + ' ' + LastName  from [Student].[dbo].[tblTeacher] t , [Student].[dbo].[tblPerson] p where p.ID = t.ID and TeacherCode = :user ");
    qry.bindValue(":user", user);
    qry.exec();
    while(qry.next()){
        fullname = qry.value(0).toString();
    }
    ui->label_name->setText(fullname);
    ui->label_TeacherCode->setText(user);
}

teachermaindialog::~teachermaindialog()
{
    delete ui;
}

void teachermaindialog::on_pushButton_setting_clicked()
{
    teachpass = new teacherchangepassword(this);
    teachpass->show();
}

void teachermaindialog::on_pushButton_clicked()
{
//    teacherchangepassword::lessoncode = ui->lineEdit_lesscode->text();
}

void teachermaindialog::on_pushButton_3_clicked()
{
//    teacherchangepassword::lessoncode = ui->lineEdit_lesscode->text();
    jozve = new sendjozve(this);
    jozve->show();
}
