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

    createNameEdit = ui->createNameEdit;
    editNameEdit = ui->editNameEdit;
    classCombo = ui->classCombo;
    createPriorityBox = ui->createPriorityBox;
    editPriorityBox = ui->editPriorityBox;

    createButton = ui->createButton;
    deleteButton = ui->deleteButton;
    blockButton = ui->blockButton;
    unblockButton = ui->unblockButton;
    suspendButton = ui->suspendButton;
    resumeButton = ui->resumeButton;
    showButton = ui->showButton;
    changePriorityButton = ui->changePriorityButton;

    classCombo->addItem("Application");
    classCombo->addItem("System");

    connect(createButton,SIGNAL(clicked()),this,SLOT(createClicked()));
    connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteClicked()));
    connect(blockButton,SIGNAL(clicked()),this,SLOT(blockClicked()));
    connect(unblockButton,SIGNAL(clicked()),this,SLOT(unblockClicked()));
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

void PCBManagerDialog::createClicked()
{
    if(createNameEdit->text() != "" && Globals().globalPCBControl.findPCB(createNameEdit->text()) == NULL)
    {
        if(classCombo->currentIndex() == 0) //Application
        {
            if(Globals().globalPCBControl.setupPCB(createNameEdit->text(),createPriorityBox->value(),Application) != NULL)
            {
                createTextDialog("PCB created succesfully.");
            }
        }
        else //System
        {
            if(Globals().globalPCBControl.setupPCB(createNameEdit->text(),createPriorityBox->value(),System) != NULL)
            {
                createTextDialog("PCB created successfully.");
            }
        }
    }
    else
    {
        createTextDialog("Error creating PCB.");
    }
}

void PCBManagerDialog::deleteClicked()
{
    PCB *temp = Globals().globalPCBControl.findPCB(editNameEdit->text());
    if(temp != NULL)
    {
        Globals().globalPCBControl.freePCB(temp);
        createTextDialog("PCB deleted successfully.");
    }
    else
    {
        createTextDialog("Error deleting PCB.");
    }
}

void PCBManagerDialog::blockClicked()
{
    PCB *temp = Globals().globalPCBControl.findPCB(editNameEdit->text());
    if(temp != NULL)
    {
        temp->setRunState(Blocked);
        createTextDialog("PCB blocked.");
    }
    else
    {
        createTextDialog("Unable to block PCB.");
    }
}

void PCBManagerDialog::unblockClicked()
{
    PCB *temp = Globals().globalPCBControl.findPCB(editNameEdit->text());
    if(temp != NULL)
    {
        temp->setRunState(Ready);
        createTextDialog("PCB unblocked.");
    }
    else
    {
        createTextDialog("Unable to unblock PCB.");
    }
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
