#ifndef PARSER_H
#define PARSER_H

#include <QWidget>
#include <stdio.h>
#include <string>
#include "Lasercutter.h"


using namespace std;

class Parser
{
private:
    string Pfad;
    Lasercutter *laser;

public:
    Parser(string Pfadangabe, Lasercutter *laser);
    void checkOPs();
    void getDigits(char *pLine, int line_anz);
    int getLines();

protected:
    int Arraygroesse;

};

#endif // PARSER_H
