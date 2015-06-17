#ifndef LASERCUTTER_H
#define LASERCUTTER_H
#include "mainwindow.h"
#include "mywidget.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

class Lasercutter : public MainWindow
{


    class LaserState *current;

public:

    int Laserstate;
    int *X_Werte;
    int *Y_Werte;
    Lasercutter();

    ~Lasercutter();

    void setValues(int x, int y, int Arrayplatz);
    int* set_X_Array(int Moves);
    int* set_Y_Array(int Moves);

};

#endif // LASERCUTTER_H
