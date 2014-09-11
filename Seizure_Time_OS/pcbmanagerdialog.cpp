#include "pcbmanagerdialog.h"
#include "ui_pcbmanagerdialog.h"

PCBManagerDialog::PCBManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCBManagerDialog)
{
    textDisplay = NULL;

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
        Globals().globalPCBControl.removePCB(temp);
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

}

void PCBManagerDialog::unblockClicked()
{

}

void PCBManagerDialog::suspendClicked()
{

}

void PCBManagerDialog::resumeClicked()
{

}

void PCBManagerDialog::showClicked()
{

}

void PCBManagerDialog::changePriorityClicked()
{

}

void PCBManagerDialog::createTextDialog(QString text)
{
    delete textDisplay;
    textDisplay = new TextDialog(this,text);
}
