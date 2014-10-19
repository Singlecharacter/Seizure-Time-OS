#include "seizuretimecore.h"
#include "ui_seizuretimecore.h"

SeizureTimeCore::SeizureTimeCore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeizureTimeCore)
{
    ui->setupUi(this);


    //Initialize globals
    Globals().systemDate = QDate().currentDate();
    Globals().mainDir = QDir().homePath() + "/Seizure_Time_OS";

    //Create and show main menu
    menu = new MainMenu();
    menu->show();
}

SeizureTimeCore::~SeizureTimeCore()
{
    delete ui;
}
