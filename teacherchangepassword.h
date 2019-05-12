#ifndef TEACHERCHANGEPASSWORD_H
#define TEACHERCHANGEPASSWORD_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class teacherchangepassword;
}

class teacherchangepassword : public QDialog
{
    Q_OBJECT

public:
    explicit teacherchangepassword(QWidget *parent = nullptr);
    ~teacherchangepassword();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::teacherchangepassword *ui;
};

#endif // TEACHERCHANGEPASSWORD_H
