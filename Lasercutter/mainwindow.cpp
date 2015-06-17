#include <iostream>
#include <fstream>
#include <string>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "Parser.h"
#include "Lasercutter.h"

using namespace std;

QString fileName;
string filepath;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"), tr("Text Files(*.txt)"));

      ui->lineEdit->setText(fileName);

      filepath = fileName.toStdString();

}

void MainWindow::on_pushButton_2_clicked()
{
    int Zeilen = 0;
    int *x_array;
    int *y_array;
    ui->pushButton_2->setEnabled(false);

    Lasercutter laser;
    Parser parser = Parser(filepath,&laser);
    Zeilen = parser.getLines();                                     // Anzahl der Move-Befehle zurückgeben
    x_array = laser.set_X_Array(Zeilen);                            // Pointer auf X Arrays erstellen
    y_array = laser.set_Y_Array(Zeilen);                            // Pointer auf Y Arrays erstellen
    parser.checkOPs();                                              // parsen der einzelnen Befehle und befüllen der Arrays mit den Koordinaten

    for (int i = 0; i<Zeilen; i++)
    {
        ui->myw->move(x_array[i], y_array[i]);
    }

ui->pushButton_2->setEnabled(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->myw->Points.clear();
    ui->myw->repaint();
    ui->pushButton_2->setEnabled(true);
}

