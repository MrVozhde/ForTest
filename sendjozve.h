#ifndef SENDJOZVE_H
#define SENDJOZVE_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <teacherchangepassword.h>

namespace Ui {
class sendjozve;
}

class sendjozve : public QDialog
{
    Q_OBJECT

public:
    explicit sendjozve(QWidget *parent = nullptr);
    ~sendjozve();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::sendjozve *ui;
};

#endif // SENDJOZVE_H
