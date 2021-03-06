#ifndef LASERCUTTER_H
#define LASERCUTTER_H

#include <QMainWindow>

namespace Ui {
class Lasercutter;
}

class Lasercutter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Lasercutter(QWidget *parent = 0);
    ~Lasercutter();

private slots:
    void on_bt_browse_clicked();

private:
    Ui::Lasercutter *ui;
};

#endif // LASERCUTTER_H
