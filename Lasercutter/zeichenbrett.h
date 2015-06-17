#ifndef ZEICHENBRETT_H
#define ZEICHENBRETT_H

#include <QWidget>

class zeichenBrett : public QWidget
{
    Q_OBJECT
public:
    explicit zeichenBrett(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *e);

signals:

public slots:

};

#endif // ZEICHENBRETT_H
