#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    setWindowFlags(Qt::WindowTitleHint);
    ui->setupUi(this);

    quitDialog = NULL;
    dirDialog = NULL;
    dateDialog = NULL;
    helpDialog = NULL;
    PCBDialog = NULL;

    mainDir = QDir().homePath() + "/Seizure_Time_OS";
    QDir temp;
    temp.mkdir(mainDir);


    //Assign ui pointers
    quitButton = ui->quitButton;
    versionLabel = ui->versionLabel;
    fileListButton = ui->fileListButton;
    dateButton = ui->dateButton;
    helpButton = ui->helpButton;
    PCBButton = ui->PCBButton;

    versionLabel->setText("Version 0.1.0");
    versionLabel->adjustSize();
    versionLabel->setGeometry(width()/2-(versionLabel->width()/2),50,versionLabel->width(),versionLabel->height());

    //Quit the core process when the main menu is quit
    connect(this,SIGNAL(destroyed()),QApplication::instance(),SLOT(quit()));

    //Create a quit confirmation dialog when quit is clicked
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitButtonClicked()));

    //Create a directory list dialog when file list is clicked
    connect(fileListButton,SIGNAL(clicked()),this,SLOT(fileButtonClicked()));

    //Create a date dialog when the date button is clicked
    connect(dateButton,SIGNAL(clicked()),this,SLOT(dateButtonClicked()));

    //Create a help dialog when the help button is clicked
    connect(helpButton,SIGNAL(clicked()),this,SLOT(helpButtonClicked()));

    //Create a PCB manager when PCB button is clicked
    connect(PCBButton,SIGNAL(clicked()),this,SLOT(PCBClicked()));
}

MainMenu::~MainMenu()
{
    delete ui;
    delete quitButton;
    delete fileListButton;
    delete dateButton;
    delete quitDialog;
    delete dirDialog;
}

void MainMenu::quitButtonClicked()
{
    delete quitDialog;
    quitDialog = new QuitConfirmDialog(this);
}

void MainMenu::fileButtonClicked()
{
    delete dirDialog;
    dirDialog = new DirectoryListDialog(this, mainDir);
}

void MainMenu::dateButtonClicked()
{
    delete dateDialog;
    dateDialog = new DateDialog();
}

void MainMenu::helpButtonClicked()
{
    delete helpDialog;
    helpDialog = new HelpDialog();
}

void MainMenu::PCBClicked()
{
    delete PCBDialog;
    PCBDialog = new PCBManagerDialog();
}
