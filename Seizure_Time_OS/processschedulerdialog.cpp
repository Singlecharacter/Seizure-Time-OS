#include "processschedulerdialog.h"
#include "ui_processschedulerdialog.h"

ProcessSchedulerDialog::ProcessSchedulerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessSchedulerDialog)
{
    ui->setupUi(this);

    SJFButton = ui->SJFButton;
    loadButton = ui->loadButton;
    filenameEdit = ui->filenameEdit;
    readyQueueDisplay = ui->readyQueueDisplay;

    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadClicked()));
    connect(SJFButton,SIGNAL(clicked()),this,SLOT(SJFClicked()));

    show();
}

ProcessSchedulerDialog::~ProcessSchedulerDialog()
{
    delete ui;
}

void ProcessSchedulerDialog::loadClicked()
{
    Globals().globalPCBControl.setupFromFile(QDir().homePath() + "/Seizure_Time_OS/" + filenameEdit->text());
    printReady();
}

void ProcessSchedulerDialog::SJFClicked()
{
    scheduler.sortQueue(SJF);
    printReady();
}

void ProcessSchedulerDialog::printReady()
{
    QString readyText = "";
    qDebug() << "Ready size in printReady: " << Globals().globalPCBControl.readyQueueSize();
    for(int i = 0; i < Globals().globalPCBControl.readyQueueSize(); i++)
    {
        readyText += Globals().globalPCBControl.atReadyQueue(i)->getName();
        readyText += "\r\n";
    }

    readyQueueDisplay->setText(readyText);
}
