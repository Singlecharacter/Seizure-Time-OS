#include "processschedulerdialog.h"
#include "ui_processschedulerdialog.h"

ProcessSchedulerDialog::ProcessSchedulerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessSchedulerDialog)
{
    ui->setupUi(this);


    QRadioButton *SJFButton = ui->SJFButton;
    QRadioButton *FIFOButton = ui->FIFOButton;
    QRadioButton *STCFButton = ui->STCFButton;
    QRadioButton *FPPSButton = ui->FPPSButton;
    QRadioButton *RRButton = ui->RRButton;
    QRadioButton *MLFQButton = ui->MLFQButton;
    QRadioButton *LSButton = ui->LSButton;
    QPushButton *loadButton = ui->loadButton;
    QComboBox *memComboBox = ui->memComboBox;
    filenameEdit = ui->filenameEdit;
    readyQueueDisplay = ui->readyQueueDisplay;
    completedDisplay = ui->completedDisplay;
    QPushButton *startButton = ui->startButton;
    runningLabel = ui->runningLabel;
    runningLabel->setText("Running process: NONE");

    processTimer = new QTimer();
    processTimer->setSingleShot(false);
    processTimer->start(1);

    memComboBox->addItem("First fit");
    memComboBox->addItem("Next fit");
    memComboBox->addItem("Best fit");
    memComboBox->addItem("Worst fit");
    memComboBox->adjustSize();

    connect(processTimer,SIGNAL(timeout()),this,SLOT(processTimeout()));
    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadClicked()));
    connect(SJFButton,SIGNAL(clicked()),this,SLOT(SJFClicked()));
    connect(FIFOButton,SIGNAL(clicked()),this,SLOT(FIFOClicked()));
    connect(STCFButton,SIGNAL(clicked()),this,SLOT(STCFClicked()));
    connect(FPPSButton,SIGNAL(clicked()),this,SLOT(FPPSClicked()));
    connect(RRButton,SIGNAL(clicked()),this,SLOT(RRClicked()));
    connect(MLFQButton,SIGNAL(clicked()),this,SLOT(MLFQClicked()));
    connect(startButton,SIGNAL(clicked()),this,SLOT(startClicked()));
    connect(LSButton,SIGNAL(clicked()),this,SLOT(LSClicked()));

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
    loadClicked();
    scheduler.sortQueue(SJF);
    scheduler.currentType = SJF;
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/SJF.txt");
    scheduler.manager.fname = Globals().mainDir+"/SJF.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::FIFOClicked()
{
    loadClicked();
    scheduler.sortQueue(FIFO);
    scheduler.currentType = FIFO;
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/FIFO.txt");
    scheduler.manager.fname = Globals().mainDir+"/FIFO.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::STCFClicked()
{
    loadClicked();
    scheduler.sortQueue(STCF);
    scheduler.currentType = STCF;
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/STCF.txt");
    scheduler.manager.fname = Globals().mainDir+"/STCF.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::FPPSClicked()
{
    loadClicked();
    scheduler.sortQueue(FPPS);
    scheduler.currentType = FPPS;
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/FPPS.txt");
    scheduler.manager.fname = Globals().mainDir+"/FPPS.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::RRClicked()
{
    loadClicked();
    scheduler.sortQueue(RR);
    scheduler.currentType = RR;
    scheduler.timeQuantumSize = ui->quantumBox->value();
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/RR.txt");
    scheduler.manager.fname = Globals().mainDir+"/RR.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::MLFQClicked()
{
    loadClicked();
    scheduler.sortQueue(MLFQ);
    scheduler.currentType = MLFQ;
    scheduler.timeQuantumSize = ui->quantumBox->value();
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/MLFQ.txt");
    scheduler.manager.fname = Globals().mainDir+"/MLFQ.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::LSClicked()
{
    loadClicked();
    scheduler.sortQueue(LS);
    scheduler.currentType = LS;
    scheduler.timeQuantumSize = ui->quantumBox->value();
    printReady();
    scheduler.f.setFileName(Globals().mainDir+"/LS.txt");
    scheduler.manager.fname = Globals().mainDir+"/LS.txt";
    scheduler.manager.clearTable();
}

void ProcessSchedulerDialog::startClicked()
{
    loadClicked();
    scheduler.currentlyRunning = true;
    scheduler.f.open(QIODevice::WriteOnly);
    scheduler.fout.setDevice(&scheduler.f);
    scheduler.f.close();
    scheduler.manager.clearTable();

    if(ui->memComboBox->currentText() == "First fit")
    {
        scheduler.manager.mode = FIRST_FIT;
    }
    else if(ui->memComboBox->currentText() == "Next fit")
    {

    }
    else if(ui->memComboBox->currentText() == "Best fit")
    {

    }
    else if(ui->memComboBox->currentText() == "Worst fit")
    {

    }
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
