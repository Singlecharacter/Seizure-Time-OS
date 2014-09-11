#ifndef SEIZURETIMECORE_H
#define SEIZURETIMECORE_H

#include "mainmenu.h"
#include "globals.h"

#include <QMainWindow>
#include <QDate>

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

    MainMenu *menu;
};

#endif // SEIZURETIMECORE_H
