#ifndef EDITTEACHERDIALOG_H
#define EDITTEACHERDIALOG_H

#include <QDialog>
#include <QtSql>
#include <showteacherdialog.h>
#include <QMessageBox>

namespace Ui {
class editteacherdialog;
}

class editteacherdialog : public QDialog
{
    Q_OBJECT

public:
    explicit editteacherdialog(QWidget *parent = nullptr);
    ~editteacherdialog();

private slots:
    void on_pushButton_showAllStudent_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_apply_clicked();

private:
    Ui::editteacherdialog *ui;
    showteacherdialog *showtea ;
};

#endif // EDITTEACHERDIALOG_H
