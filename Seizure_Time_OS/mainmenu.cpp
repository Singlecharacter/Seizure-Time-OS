#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    quitDialog = NULL;

    //Assign ui pointers
    quitButton = ui->quitButton;

    //Quit the core process when the main menu is quit
    connect(this,SIGNAL(destroyed()),QApplication::instance(),SLOT(quit()));

    //Create a quit confirmation dialog when quit is clicked
    connect(quitButton,SIGNAL(clicked()),this,SLOT(quitButtonClicked()));
}

MainMenu::~MainMenu()
{
    delete ui;
    delete quitButton;
    delete quitDialog;
}

void MainMenu::quitButtonClicked()
{
    delete quitDialog;
    quitDialog = new QuitConfirmDialog(this);
    quitDialog->show();
}
