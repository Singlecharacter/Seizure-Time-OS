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

    mainDir = QDir().homePath() + "/Seizure_Time_OS";
    QDir temp;
    temp.mkdir(mainDir);

    //Assign ui pointers
    quitButton = ui->quitButton;
    versionLabel = ui->versionLabel;
    fileListButton = ui->fileListButton;

    versionLabel->setText("Version 0.0.2");
    versionLabel->adjustSize();
    versionLabel->setGeometry(width()/2-(versionLabel->width()/2),50,versionLabel->width(),versionLabel->height());

    //Quit the core process when the main menu is quit
    connect(this,SIGNAL(destroyed()),QApplication::instance(),SLOT(quit()));

    //Create a quit confirmation dialog when quit is clicked
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitButtonClicked()));

    //Create a directory list dialog when file list is clicked
    connect(fileListButton,SIGNAL(clicked()),this,SLOT(fileButtonClicked()));
}

MainMenu::~MainMenu()
{
    delete ui;
    delete quitButton;
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
