#include "show_student_lesson.h"
#include "ui_show_student_lesson.h"

show_student_lesson::show_student_lesson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::show_student_lesson)
{
    ui->setupUi(this);
}

show_student_lesson::~show_student_lesson()
{
    delete ui;
}
