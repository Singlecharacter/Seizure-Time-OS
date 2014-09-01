/********************************************************************************
** Form generated from reading UI file 'seizuretimecore.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEIZURETIMECORE_H
#define UI_SEIZURETIMECORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeizureTimeCore
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SeizureTimeCore)
    {
        if (SeizureTimeCore->objectName().isEmpty())
            SeizureTimeCore->setObjectName(QStringLiteral("SeizureTimeCore"));
        SeizureTimeCore->resize(400, 300);
        menuBar = new QMenuBar(SeizureTimeCore);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SeizureTimeCore->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SeizureTimeCore);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SeizureTimeCore->addToolBar(mainToolBar);
        centralWidget = new QWidget(SeizureTimeCore);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SeizureTimeCore->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SeizureTimeCore);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SeizureTimeCore->setStatusBar(statusBar);

        retranslateUi(SeizureTimeCore);

        QMetaObject::connectSlotsByName(SeizureTimeCore);
    } // setupUi

    void retranslateUi(QMainWindow *SeizureTimeCore)
    {
        SeizureTimeCore->setWindowTitle(QApplication::translate("SeizureTimeCore", "SeizureTimeCore", 0));
    } // retranslateUi

};

namespace Ui {
    class SeizureTimeCore: public Ui_SeizureTimeCore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEIZURETIMECORE_H
