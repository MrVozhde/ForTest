#ifndef ADDTEACHERDIALOG_H
#define ADDTEACHERDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <showteacherdialog.h>

namespace Ui {
class addteacherdialog;
}

class addteacherdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addteacherdialog(QWidget *parent = nullptr);
    ~addteacherdialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::addteacherdialog *ui;
    showteacherdialog *showteadialog ;
};

#endif // ADDTEACHERDIALOG_H
