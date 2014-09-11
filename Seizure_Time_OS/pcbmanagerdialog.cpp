#include "pcbmanagerdialog.h"
#include "ui_pcbmanagerdialog.h"

PCBManagerDialog::PCBManagerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PCBManagerDialog)
{
    textDisplay = NULL;

    ui->setupUi(this);

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
            Globals().globalPCBControl.setupPCB(createNameEdit->text(),createPriorityBox->value(),Application);
        }
        else
        {
            Globals().globalPCBControl.setupPCB(createNameEdit->text(),createPriorityBox->value(),Application);
        }
        createTextDialog("PCB created successfully.");
    }
    else
    {
        createTextDialog("Error creating PCB.");
    }
}

void PCBManagerDialog::deleteClicked()
{

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
