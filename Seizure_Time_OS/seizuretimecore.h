#ifndef SEIZURETIMECORE_H
#define SEIZURETIMECORE_H

#include <QMainWindow>

namespace Ui {
class SeizureTimeCore;
}

class SeizureTimeCore : public QMainWindow
{
    Q_OBJECT

public:
    explicit SeizureTimeCore(QWidget *parent = 0);
    ~SeizureTimeCore();

private:
    Ui::SeizureTimeCore *ui;
};

#endif // SEIZURETIMECORE_H
