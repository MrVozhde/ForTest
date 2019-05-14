#ifndef SHOW_STUDENT_LESSON_H
#define SHOW_STUDENT_LESSON_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class show_student_lesson;
}

class show_student_lesson : public QDialog
{
    Q_OBJECT

public:
    explicit show_student_lesson(QWidget *parent = nullptr);
    ~show_student_lesson();

private:
    Ui::show_student_lesson *ui;

};

#endif // SHOW_STUDENT_LESSON_H
