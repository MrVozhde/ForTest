#ifndef STUDENTMAINDIALOG_H
#define STUDENTMAINDIALOG_H

#include <QDialog>

namespace Ui {
class studentmaindialog;
}

class studentmaindialog : public QDialog
{
    Q_OBJECT

public:
    explicit studentmaindialog(QWidget *parent = nullptr);
    ~studentmaindialog();

private slots:
    void on_pushButton_exit_clicked();

private:
    Ui::studentmaindialog *ui;
};

#endif // STUDENTMAINDIALOG_H
