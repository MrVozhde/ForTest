#ifndef SHOWTEACHERDIALOG_H
#define SHOWTEACHERDIALOG_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class showteacherdialog;
}

class showteacherdialog : public QDialog
{
    Q_OBJECT

public:
    explicit showteacherdialog(QWidget *parent = nullptr);
    ~showteacherdialog();

private:
    Ui::showteacherdialog *ui;    
    QSqlQueryModel *qry;
};

#endif // SHOWTEACHERDIALOG_H
