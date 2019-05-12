#include "sendjozve.h"
#include "ui_sendjozve.h"

sendjozve::sendjozve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sendjozve)
{
    ui->setupUi(this);
}

sendjozve::~sendjozve()
{
    delete ui;
}
