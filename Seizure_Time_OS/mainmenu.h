#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QPushButton>

#include "quitconfirmdialog.h"

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

private:
    Ui::MainMenu *ui;

    QuitConfirmDialog *quitDialog;

    //Pointers to ui elements
    QPushButton *quitButton;
};

#endif // MAINMENU_H
