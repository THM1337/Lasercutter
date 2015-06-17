#include "zeichenbrett.h"
#include "qpainter.h"

zeichenBrett::zeichenBrett(QWidget *parent) :
    QWidget(parent)
{

}

void zeichenBrett::paintEvent(QPaintEvent *e)
{
    QPainter Painter(this);


   Painter.drawLine(1,1,20,30);             // int x1, int y1, int x2, int y2
}
