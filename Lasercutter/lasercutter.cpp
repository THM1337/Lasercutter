#include "lasercutter.h"
#include "ui_lasercutter.h"

Lasercutter::Lasercutter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Lasercutter)
{
    ui->setupUi(this);
}

Lasercutter::~Lasercutter()
{
    delete ui;
}
