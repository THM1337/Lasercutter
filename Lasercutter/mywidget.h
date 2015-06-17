#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QVector>

class MyWidget : public QWidget

{
    Q_OBJECT

public:

    explicit MyWidget(QWidget *parent = 0);
    int x_1,y_1,x_2,y_2,i;

    void move(int,int);
    QVector<QPoint> Points;

    QPoint ConvertIntoQPoint(int x, int y);
protected:

    void paintEvent(QPaintEvent*);

signals:

public slots:
};

#endif // MYWIDGET_H
