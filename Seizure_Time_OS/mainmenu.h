#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDir>
#include <QStringList>
#include <QString>

#include "quitconfirmdialog.h"
#include "directorylistdialog.h"
#include "datedialog.h"
#include "multipagedialog.h"
#include "pcbmanagerdialog.h"
#include "globals.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:

    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

private slots:

    void quitButtonClicked();
    void fileButtonClicked();
    void dateButtonClicked();
    void helpButtonClicked();
    void PCBClicked();

private:

    Ui::MainMenu *ui;

    //Dialog pointers for functionality
    QuitConfirmDialog *quitDialog;
    DirectoryListDialog *dirDialog;
    DateDialog *dateDialog;
    MultiPageDialog *helpDialog;
    PCBManagerDialog *PCBDialog;

    QString mainDir;
    QStringList helpLibrary;

    //Pointers to ui elements
    QPushButton *quitButton;
    QPushButton *fileListButton;
    QPushButton *dateButton;
    QPushButton *helpButton;
    QPushButton *PCBButton;
    QLabel *versionLabel;
};

#endif // MAINMENU_H
