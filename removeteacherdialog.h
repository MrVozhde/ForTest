#ifndef REMOVETEACHERDIALOG_H
#define REMOVETEACHERDIALOG_H

#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <showteacherdialog.h>

namespace Ui {
class removeteacherdialog;
}

class removeteacherdialog : public QDialog
{
    Q_OBJECT

public:
    explicit removeteacherdialog(QWidget *parent = nullptr);
    ~removeteacherdialog();

private slots:
    void on_pushButton_showAllStu_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::removeteacherdialog *ui;
    showteacherdialog *showteadialog ;
};

#endif // REMOVETEACHERDIALOG_H
