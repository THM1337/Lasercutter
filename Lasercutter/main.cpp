#include "lasercutter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lasercutter w;
    w.show();

    return a.exec(); //MÖÖÖÖP
}
