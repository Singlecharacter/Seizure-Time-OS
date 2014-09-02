#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QDir>

#include "quitconfirmdialog.h"
#include "directorylistdialog.h"

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

private:
    Ui::MainMenu *ui;

    QuitConfirmDialog *quitDialog;
    DirectoryListDialog *dirDialog;

    QString mainDir;

    //Pointers to ui elements
    QPushButton *quitButton;
    QPushButton *fileListButton;
    QLabel *versionLabel;
};

#endif // MAINMENU_H
