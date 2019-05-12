#include "teachermaindialog.h"
#include "ui_teachermaindialog.h"

teachermaindialog::teachermaindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teachermaindialog)
{
    ui->setupUi(this);
    this->model = new QSqlQueryModel();
    model->setQuery("SELECT    dbo.tblLesson.Title as 'نام درس', dbo.tblLesson.LessonCode as 'کد درس', dbo.tblLesson.Type as 'نوع', dbo.tblLesson.TedadVahedas 'تعداد واحد', dbo.tblErae.DaysOfWeek as 'روزهای برگزاری' , dbo.tblErae.TimeOfClass as 'زمان کلاس'\
                    FROM      dbo.tblEntekhabVahed INNER JOIN \
                              dbo.tblErae ON dbo.tblEntekhabVahed.ID_Erae = dbo.tblErae.ID INNER JOIN \
                              dbo.tblLesson ON dbo.tblErae.ID_Lesson = dbo.tblLesson.ID");
            ui->tableView->setModel(model);

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
    QString lessoncode = ui->lineEdit_lesscode->text();
}

void teachermaindialog::on_pushButton_3_clicked()
{
    jozve = new sendjozve(this);
    jozve->show();
}
