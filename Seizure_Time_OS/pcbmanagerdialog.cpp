#include "pcbmanagerdialog.h"
#include "ui_pcbmanagerdialog.h"

PCBManagerDialog::PCBManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCBManagerDialog)
{
    textDisplay = NULL;
    showDialog = NULL;

    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);

    editNameEdit = ui->editNameEdit;
    editPriorityBox = ui->editPriorityBox;

    suspendButton = ui->suspendButton;
    resumeButton = ui->resumeButton;
    showButton = ui->showButton;
    changePriorityButton = ui->changePriorityButton;

    connect(suspendButton,SIGNAL(clicked()),this,SLOT(suspendClicked()));
    connect(resumeButton,SIGNAL(clicked()),this,SLOT(resumeClicked()));
    connect(showButton,SIGNAL(clicked()),this,SLOT(showClicked()));
    connect(changePriorityButton,SIGNAL(clicked()),this,SLOT(changePriorityClicked()));

    show();
}

PCBManagerDialog::~PCBManagerDialog()
{
    delete ui;
}

void PCBManagerDialog::suspendClicked()
{
    PCB *temp = Globals().globalPCBControl.findPCB(editNameEdit->text());
    if(temp != NULL)
    {
        temp->setSuspendState(Suspended);
        createTextDialog("PCB suspended.");
    }
    else
    {
        createTextDialog("Unable to suspend PCB.");
    }
}

void PCBManagerDialog::resumeClicked()
{
    PCB *temp = Globals().globalPCBControl.findPCB(editNameEdit->text());
    if(temp != NULL)
    {
        temp->setSuspendState(NotSuspended);
        createTextDialog("PCB resumed.");
    }
    else
    {
        createTextDialog("Unable to resume PCB.");
    }
}

void PCBManagerDialog::showClicked()
{
    QStringList PCBDisplayList;
    PCBDisplayList.clear();
    QStringList pages;
    pages.clear();
    QString page = "";
    QString pageAddition = "";

    if(Globals().globalPCBControl.readyQueueSize() > 0 || Globals().globalPCBControl.blockedQueueSize() > 0)
    {
        for(int i = 0; i < Globals().globalPCBControl.readyQueueSize();i++)
        {
            PCB *temp = Globals().globalPCBControl.atReadyQueue(i);
            page = temp->getName();
            page += "\r\n\r\n";
            page += "Class: ";
            if(temp->getClass() == Application)
            {
                page += "Application";
            }
            else
            {
                page += "System";
            }
            page += "\r\n";
            page += "Priority: ";
            pageAddition.setNum(temp->getPriority());
            page += pageAddition;
            page += "\r\n";
            page += "State: ";
            if(temp->getRunState() == Ready)
            {
                page += "Ready";
            }
            else if(temp->getRunState() == Running)
            {
                page += "Running";
            }
            else
            {
                page += "Blocked";
            }
            page += "\r\n";
            page += "Suspended: ";
            if(temp->getSuspendState() == Suspended)
            {
                page += "Yes";
            }
            else
            {
                page += "No";
            }
            page += "\r\n";
            page += "Memory: ";
            pageAddition.setNum(temp->getRequiredMemory());
            page += pageAddition;

            pages.push_back(page);
        }

        for(int i = 0; i < Globals().globalPCBControl.blockedQueueSize();i++)
        {
            PCB *temp = Globals().globalPCBControl.atBlockedQueue(i);
            page = temp->getName();
            page += "\r\n\r\n";
            page += "Class: ";
            if(temp->getClass() == Application)
            {
                page += "Application";
            }
            else
            {
                page += "System";
            }
            page += "\r\n";
            page += "Priority: ";
            pageAddition.setNum(temp->getPriority());
            page += pageAddition;
            page += "\r\n";
            page += "State: ";
            if(temp->getRunState() == Ready)
            {
                page += "Ready";
            }
            else if(temp->getRunState() == Running)
            {
                page += "Running";
            }
            else
            {
                page += "Blocked";
            }
            page += "\r\n";
            page += "Suspended: ";
            if(temp->getSuspendState() == Suspended)
            {
                page += "Yes";
            }
            else
            {
                page += "No";
            }
            page += "\r\n";
            page += "Memory: ";
            pageAddition.setNum(temp->getRequiredMemory());
            page += pageAddition;

            pages.push_back(page);
        }

        delete showDialog;
        showDialog = new MultiPageDialog(this,pages);
    }
    else
    {
        createTextDialog("No PCBs to show!");
    }
}

void PCBManagerDialog::changePriorityClicked()
{
    PCB *temp = Globals().globalPCBControl.findPCB(editNameEdit->text());
    if(temp != NULL)
    {
        temp->setPriority(editPriorityBox->value());
        createTextDialog("PCB priority changed.");
    }
    else
    {
        createTextDialog("Unable to change PCB priority.");
    }
}

void PCBManagerDialog::createTextDialog(QString text)
{
    delete textDisplay;
    textDisplay = new TextDialog(this,text);
}
