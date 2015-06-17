#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "Lasercutter.h"

using namespace std;


Parser::Parser(string Pfad, Lasercutter *laser)
{
    this->Pfad = Pfad;
    this->laser = laser;
}

void Parser::checkOPs()
{
    //string line;
    ifstream Quelldatei;

    Quelldatei.open(Pfad.c_str(), ios::in);

    if (!Quelldatei)
    {
        cerr << "Datei kann nicht geöffnet werden!\n";
    }
    else
    {
        char line[20];
        int line_anz = 0;

        while (Quelldatei.getline(line, 19))
        {
            if (line[0] == 'M' && (line[3] == 'E'))
            {
                getDigits(line, line_anz);				// Koordinaten extrahieren
                line_anz++;								// Bei jedem move ein arrayplatz weiter für den nächsten

                    //laser->lasern();
            }
            if ((line[0] == 'L') && (line[4] == 'R'))
            {
                if (line[7] == 'N')						// falls Laser oN
                {
                    //laser->on();						// Kringel uff sich selbst
                    laser->Laserstate = 1;
                }
                else									// falls Laser oFfs
                {
                    //laser->on();						// Nicht mehr malen
                    laser->Laserstate = 0;
                }

            }
        }
    }
}



void Parser::getDigits(char *pLine, int zeile)
{
    int Platz = 0;
    int iLen, iDigit, i;
    int x = 0;
    int y = 0;

    iLen = (int)strlen(pLine);
    for (i = 0; i < iLen; i++)
    {
        if (isdigit((int)pLine[i]))
        {
            iDigit = atoi(pLine+i);
            if (Platz == 0)						// platz=0 --> der x wert
            {
                x = iDigit;
                Platz++;
            }
            else
            {
                y = iDigit;						// platz=1 --> der y wert
            }

            while (isdigit((int)pLine[++i]));
        }
    }
    laser->setValues(x, y, zeile);				// Werte an lasercutter übergeben
}

int Parser::getLines()
{
    ifstream Quelldatei;

    Quelldatei.open(Pfad.c_str(), ios::in);

    if (!Quelldatei)
    {
        cerr << "Datei kann nicht geöffnet werden!\n";
    }
    else
    {
        char line[20];
        Arraygroesse = 0;

        while (Quelldatei.getline(line, 19))
        {
            if (line[0] == 'M' && (line[3] == 'E'))
            {
                Arraygroesse++;
            }
        }
    }


    return Arraygroesse;
}
