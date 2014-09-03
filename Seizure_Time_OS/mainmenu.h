#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDir>

#include "quitconfirmdialog.h"
#include "directorylistdialog.h"
#include "datedialog.h"
#include "helpdialog.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:

    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

    void setMyDate(QDate newDate);

private slots:

    void quitButtonClicked();
    void fileButtonClicked();
    void dateButtonClicked();
    void helpButtonClicked();

private:

    Ui::MainMenu *ui;

    //Dialog pointers for functionality
    QuitConfirmDialog *quitDialog;
    DirectoryListDialog *dirDialog;
    DateDialog *dateDialog;
    HelpDialog *helpDialog;

    QString mainDir;

    QDate myDate;

    //Pointers to ui elements
    QPushButton *quitButton;
    QPushButton *fileListButton;
    QPushButton *dateButton;
    QPushButton *helpButton;
    QLabel *versionLabel;
};

#endif // MAINMENU_H
