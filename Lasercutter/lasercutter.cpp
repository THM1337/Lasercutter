#include "lasercutter.h"
#include "ui_lasercutter.h"
#include "QFileDialog"

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

void Lasercutter::on_bt_browse_clicked()
{
    QString filename;

    filename = QFileDialog::getOpenFileName(this, "Search path to OP-Code", "OP Code File", tr("TextFiles(*.txt)"));

    ui->tb_path->setText(filename);
}
