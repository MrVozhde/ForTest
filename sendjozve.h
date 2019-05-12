#ifndef SENDJOZVE_H
#define SENDJOZVE_H

#include <QDialog>

namespace Ui {
class sendjozve;
}

class sendjozve : public QDialog
{
    Q_OBJECT

public:
    explicit sendjozve(QWidget *parent = nullptr);
    ~sendjozve();

private:
    Ui::sendjozve *ui;
};

#endif // SENDJOZVE_H
