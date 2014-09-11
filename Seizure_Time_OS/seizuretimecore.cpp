#include "seizuretimecore.h"
#include "ui_seizuretimecore.h"

SeizureTimeCore::SeizureTimeCore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeizureTimeCore)
{
    ui->setupUi(this);

    //Create and show main menu
    menu = new MainMenu();
    menu->show();

    //Initialize globals
    Globals().systemDate = QDate().currentDate();
}

SeizureTimeCore::~SeizureTimeCore()
{
    delete ui;
}
