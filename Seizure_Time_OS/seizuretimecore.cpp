#include "seizuretimecore.h"
#include "ui_seizuretimecore.h"

SeizureTimeCore::SeizureTimeCore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SeizureTimeCore)
{
    ui->setupUi(this);
}

SeizureTimeCore::~SeizureTimeCore()
{
    delete ui;
}
