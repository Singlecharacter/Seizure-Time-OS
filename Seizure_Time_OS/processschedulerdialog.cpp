#include "processschedulerdialog.h"
#include "ui_processschedulerdialog.h"

ProcessSchedulerDialog::ProcessSchedulerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessSchedulerDialog)
{
    qDebug() << "Setting up process scheduler.";

    ui->setupUi(this);

    SJFButton = ui->SJFButton;
    FIFOButton = ui->FIFOButton;
    QRadioButton *STCFButton = ui->STCFButton;
    loadButton = ui->loadButton;
    filenameEdit = ui->filenameEdit;
    readyQueueDisplay = ui->readyQueueDisplay;
    completedDisplay = ui->completedDisplay;
    startButton = ui->startButton;
    //runningLabel = ui->runningLabel;
    processTimer = new QTimer();
    processTimer->setSingleShot(false);
    processTimer->start(1000);

    qDebug() << "Pointers allocated.";

    connect(processTimer,SIGNAL(timeout()),this,SLOT(processTimeout()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadClicked()));
    connect(SJFButton,SIGNAL(clicked()),this,SLOT(SJFClicked()));
    connect(FIFOButton,SIGNAL(clicked()),this,SLOT(FIFOClicked()));
    connect(STCFButton,SIGNAL(clicked()),this,SLOT(STCFClicked()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(startClicked()));

    show();
}

ProcessSchedulerDialog::~ProcessSchedulerDialog()
{
    delete ui;
}

void ProcessSchedulerDialog::loadClicked()
{
    Globals().globalPCBControl.setupFromFile(QDir().homePath() + "/Seizure_Time_OS/" + filenameEdit->text());
    scheduler.currentlyRunning = false;
    scheduler.systemTime = 0;
    runningLabel->setText("Running process: NONE");
    runningLabel->adjustSize();
    scheduler.completedProcesses.clear();
    printCompleted();
    printReady();
}

void ProcessSchedulerDialog::SJFClicked()
{
    scheduler.sortQueue(SJF);
    scheduler.currentType = SJF;
    printReady();
}

void ProcessSchedulerDialog::FIFOClicked()
{
    scheduler.sortQueue(FIFO);
    scheduler.currentType = FIFO;
    printReady();
}

void ProcessSchedulerDialog::STCFClicked()
{
    scheduler.sortQueue(STCF);
    scheduler.currentType = STCF;
    printReady();
}

void ProcessSchedulerDialog::startClicked()
{
    scheduler.currentlyRunning = true;
    qDebug() << scheduler.currentlyRunning;
}

void ProcessSchedulerDialog::printReady()
{
    QString readyText = "";
    for(int i = 0; i < Globals().globalPCBControl.readyQueueSize(); i++)
    {
        readyText += Globals().globalPCBControl.atReadyQueue(i)->getName();
        readyText += "\r\n";
    }

    readyQueueDisplay->setText(readyText);
}

void ProcessSchedulerDialog::printCompleted()
{
    QString completedText = "";
    for(int i = 0; i < scheduler.completedProcesses.size(); i++)
    {
        completedText += scheduler.completedProcesses.at(i);
        completedText += "\r\n";
    }
    completedDisplay->setText(completedText);
}

void ProcessSchedulerDialog::processTimeout()
{
    scheduler.processTimeout();
    printReady();
    printCompleted();
    runningLabel->setText("Running process: " + scheduler.getRunningName());
    runningLabel->adjustSize();
}
