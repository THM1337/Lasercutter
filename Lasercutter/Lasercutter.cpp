#include <iostream>
#include <fstream>
#include <string>
#include "mainwindow.h"
#include "mywidget.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "Lasercutter.h"

using namespace std;

Lasercutter::Lasercutter()
{
    //current = new OFF;
    //int Laserstate = 0;
    //int *X_Werte = NULL;
    //int *Y_Werte = NULL;
}


Lasercutter::~Lasercutter()
{
}

/*void Lasercutter::on()
{
    current->on(this);
    Laserstate = 1;
}

void Lasercutter::off()
{
    current->off(this);
    Laserstate = 0;
}

void Lasercutter::lasern()
{
    if (Laserstate == 1)
    {
        current->lasert(this);
    }
    else
    {
        cout << "Laser bewegt sich nur!" << endl;
    }
}

void Lasercutter::setCurrent(LaserState *s)
{
    current = s;
}

void Lasercutter::bewegen()
{
    cout << "Laser bewegt sich nur!" << endl;
}*/

void Lasercutter::setValues(int x, int y, int Arrayplatz)
{
    X_Werte[Arrayplatz] = x;
    Y_Werte[Arrayplatz] = y;

}

int* Lasercutter::set_X_Array(int Moves)
{
    X_Werte = new int[Moves];												// Array für X-Werte anhand der gefundenen MOVES erstellen
    return X_Werte;
}

int* Lasercutter::set_Y_Array(int Moves)
{
    Y_Werte = new int[Moves];												// Array für Y-Werte anhand der gefundenen MOVES erstellen
    return Y_Werte;
}

