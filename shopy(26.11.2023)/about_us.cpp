#include "about_us.h"
#include "ui_about_us.h"

About_us::About_us(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_us)
{
    ui->setupUi(this);
}

About_us::~About_us()
{
    delete ui;
}
