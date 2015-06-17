#include "mywidget.h"
#include <QPainter>
#include <QThread>
#include <iostream>
#include <stdio.h>
#include <QPoint>
#include <unistd.h>

using namespace std;



MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
}


void MyWidget::move(int x_in, int y_in)
{

   //QThread thread;


   Points.push_back(MyWidget::ConvertIntoQPoint(x_in,y_in));        // Konvertierte Punkte werden in den Vector gespeichert

   if(Points.size() > 1)                                            // Sobal der Vektor mehr als 1 Point hat werden alle Punkte doppelt in den Vector gespeichert damit die Punktepaare stimmen
   {
       Points.push_back(MyWidget::ConvertIntoQPoint(x_in,y_in));
   }

        repaint();                                                  // Das Paint Event wird aufgerufen
         //update();
        //thread.sleep(1);                                            // 1 Sek. Pause
        usleep(250000);


    // Testausgabe um Inhalt von Vector auszugeben

    for (int a = 0; a < Points.size(); a++)
    {
        cout << Points.at(a).x() << " / ";
        cout << Points.at(a).y() << endl;
    }

   //-------------------------------------------

}

void MyWidget::paintEvent(QPaintEvent*)
{


    QPainter painter(this);

        QPen myPen (Qt::black, 2, Qt::SolidLine);
        painter.setPen(myPen);


        painter.drawLines(Points);                      //Alle Punktepaare werden gezeichnet.


        cout << "Aufruf" << endl;


}

QPoint MyWidget::ConvertIntoQPoint(int x, int y)
{
    //Die Methode konvertiert x und y Werte in einen Punkt zusammen

    return QPoint(x,y);

}
