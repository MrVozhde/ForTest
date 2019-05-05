#include "showteacherdialog.h"
#include "ui_showteacherdialog.h"

showteacherdialog::showteacherdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showteacherdialog)
{
    ui->setupUi(this);

    qry = new QSqlQueryModel(this);

    qry->setQuery("Select TeacherCode as 'شماره کارمندی', FirstName + ' ' + LastName as 'نام', EducationDegree as ' مدرک', NationalCode as 'کد ملی', Age as 'سن' \
                  From student.dbo.tblPerson , student.dbo.tblTeacher \
                  Where tblPerson.ID = tblTeacher.ID");
    ui->treeView->setModel(qry);
}

showteacherdialog::~showteacherdialog()
{
    delete ui;
}
