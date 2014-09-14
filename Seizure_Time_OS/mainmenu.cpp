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

    //Setup help library
    helpLibrary.clear();
    helpLibrary.push_back("Command: File List\r\n\r\nThe File List button opens a dialog window containing a scrollable text area that contains a list of all files and directories in the operating system's base directory, which by default is (User directory)/Seizure_Time_OS. Files are listed with extensions, while directories appear without any extensions.");
    helpLibrary.push_back("Command: Date\r\n\r\nThe Date button opens a dialog window containing a text display of the operating system's current date and a field for editing that date.");
    helpLibrary.push_back("Command: Quit\r\n\r\nThe Quit button opens a dialog window that asks if you're sure you want to quit and waits for your response.");

    //Assign ui pointers
    quitButton = ui->quitButton;
    versionLabel = ui->versionLabel;
    fileListButton = ui->fileListButton;
    dateButton = ui->dateButton;
    helpButton = ui->helpButton;
    PCBButton = ui->PCBButton;

    versionLabel->setText("Version 0.2.0");
    versionLabel->adjustSize();
    versionLabel->setGeometry(width()/2-(versionLabel->width()/2),50,versionLabel->width(),versionLabel->height());

    //Quit the core process when the main menu is quit
    connect(this,SIGNAL(destroyed()),QApplication::instance(),SLOT(quit()));

    //Create a quit confirmation dialog when quit is clicked
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitClicked()));

    //Create a directory list dialog when file list is clicked
    connect(fileListButton,SIGNAL(clicked()),this,SLOT(fileClicked()));

    //Create a date dialog when the date button is clicked
    connect(dateButton,SIGNAL(clicked()),this,SLOT(dateClicked()));

    //Create a help dialog when the help button is clicked
    connect(helpButton,SIGNAL(clicked()),this,SLOT(helpClicked()));

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

void MainMenu::quitClicked()
{
    delete quitDialog;
    quitDialog = new QuitConfirmDialog(this);
}

void MainMenu::fileClicked()
{
    delete dirDialog;
    dirDialog = new DirectoryListDialog(this, mainDir);
}

void MainMenu::dateClicked()
{
    delete dateDialog;
    dateDialog = new DateDialog();
}

void MainMenu::helpClicked()
{
    delete helpDialog;
    helpDialog = new MultiPageDialog(this,helpLibrary);
}

void MainMenu::PCBClicked()
{
    delete PCBDialog;
    PCBDialog = new PCBManagerDialog();
}
