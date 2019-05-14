#ifndef TEACHERMAINDIALOG_H
#define TEACHERMAINDIALOG_H

#include <QDialog>
#include <QtSql>
#include <teacherchangepassword.h>
#include <sendjozve.h>

namespace Ui {
class teachermaindialog;
}

class teachermaindialog : public QDialog
{
    Q_OBJECT

public:


    explicit teachermaindialog(QWidget *parent = nullptr);
    ~teachermaindialog();

private slots:
    void on_pushButton_setting_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::teachermaindialog *ui;
    QSqlQueryModel *model ;
    teacherchangepassword *teachpass ;
    sendjozve *jozve ;
};

#endif // TEACHERMAINDIALOG_H
