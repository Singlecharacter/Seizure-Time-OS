/********************************************************************************
** Form generated from reading UI file 'mainmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QPushButton *quitButton;
    QLabel *welcomeLabel;
    QPushButton *helpButton;
    QLabel *versionLabel;
    QPushButton *fileListButton;
    QPushButton *dateButton;
    QPushButton *PCBButton;
    QPushButton *processButton;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QStringLiteral("MainMenu"));
        MainMenu->resize(400, 300);
        MainMenu->setMinimumSize(QSize(400, 300));
        MainMenu->setMaximumSize(QSize(400, 300));
        quitButton = new QPushButton(MainMenu);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        quitButton->setEnabled(true);
        quitButton->setGeometry(QRect(310, 260, 75, 23));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);
        welcomeLabel = new QLabel(MainMenu);
        welcomeLabel->setObjectName(QStringLiteral("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(40, 20, 316, 29));
        QFont font;
        font.setPointSize(18);
        welcomeLabel->setFont(font);
        helpButton = new QPushButton(MainMenu);
        helpButton->setObjectName(QStringLiteral("helpButton"));
        helpButton->setGeometry(QRect(360, 10, 32, 32));
        sizePolicy.setHeightForWidth(helpButton->sizePolicy().hasHeightForWidth());
        helpButton->setSizePolicy(sizePolicy);
        helpButton->setToolTipDuration(-1);
        helpButton->setFlat(false);
        versionLabel = new QLabel(MainMenu);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setGeometry(QRect(150, 50, 63, 13));
        fileListButton = new QPushButton(MainMenu);
        fileListButton->setObjectName(QStringLiteral("fileListButton"));
        fileListButton->setGeometry(QRect(20, 260, 75, 23));
        dateButton = new QPushButton(MainMenu);
        dateButton->setObjectName(QStringLiteral("dateButton"));
        dateButton->setGeometry(QRect(20, 230, 75, 23));
        PCBButton = new QPushButton(MainMenu);
        PCBButton->setObjectName(QStringLiteral("PCBButton"));
        PCBButton->setGeometry(QRect(100, 260, 75, 23));
        processButton = new QPushButton(MainMenu);
        processButton->setObjectName(QStringLiteral("processButton"));
        processButton->setGeometry(QRect(200, 260, 101, 23));

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QApplication::translate("MainMenu", "Seizure Time Menu", 0));
        quitButton->setText(QApplication::translate("MainMenu", "Quit", 0));
        welcomeLabel->setText(QApplication::translate("MainMenu", "Welcome to Seizure Time OS", 0));
#ifndef QT_NO_TOOLTIP
        helpButton->setToolTip(QApplication::translate("MainMenu", "Help", 0));
#endif // QT_NO_TOOLTIP
        helpButton->setText(QApplication::translate("MainMenu", "?", 0));
        versionLabel->setText(QApplication::translate("MainMenu", "Version 0.0.0", 0));
        fileListButton->setText(QApplication::translate("MainMenu", "File List", 0));
        dateButton->setText(QApplication::translate("MainMenu", "Date", 0));
        PCBButton->setText(QApplication::translate("MainMenu", "PCB Manager", 0));
        processButton->setText(QApplication::translate("MainMenu", "Process Scheduler", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
