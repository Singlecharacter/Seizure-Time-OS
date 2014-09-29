/********************************************************************************
** Form generated from reading UI file 'processschedulerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSSCHEDULERDIALOG_H
#define UI_PROCESSSCHEDULERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ProcessSchedulerDialog
{
public:
    QLineEdit *filenameEdit;
    QLabel *label;
    QPushButton *loadButton;
    QTextEdit *readyQueueDisplay;
    QLabel *label_2;
    QTextEdit *completedDisplay;
    QPushButton *startButton;
    QLabel *label_3;
    QRadioButton *SJFButton;
    QRadioButton *FIFOButton;
    QRadioButton *FPPSButton;
    QRadioButton *RRButton;
    QLabel *runningLabel;
    QRadioButton *STCFButton;
    QLabel *label_4;
    QSpinBox *quantumBox;

    void setupUi(QDialog *ProcessSchedulerDialog)
    {
        if (ProcessSchedulerDialog->objectName().isEmpty())
            ProcessSchedulerDialog->setObjectName(QStringLiteral("ProcessSchedulerDialog"));
        ProcessSchedulerDialog->resize(400, 334);
        filenameEdit = new QLineEdit(ProcessSchedulerDialog);
        filenameEdit->setObjectName(QStringLiteral("filenameEdit"));
        filenameEdit->setGeometry(QRect(80, 30, 113, 20));
        label = new QLabel(ProcessSchedulerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 46, 13));
        loadButton = new QPushButton(ProcessSchedulerDialog);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(200, 30, 75, 23));
        readyQueueDisplay = new QTextEdit(ProcessSchedulerDialog);
        readyQueueDisplay->setObjectName(QStringLiteral("readyQueueDisplay"));
        readyQueueDisplay->setGeometry(QRect(20, 140, 104, 141));
        label_2 = new QLabel(ProcessSchedulerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 120, 70, 13));
        completedDisplay = new QTextEdit(ProcessSchedulerDialog);
        completedDisplay->setObjectName(QStringLiteral("completedDisplay"));
        completedDisplay->setGeometry(QRect(250, 140, 104, 141));
        startButton = new QPushButton(ProcessSchedulerDialog);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(150, 280, 75, 23));
        label_3 = new QLabel(ProcessSchedulerDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 120, 106, 13));
        SJFButton = new QRadioButton(ProcessSchedulerDialog);
        SJFButton->setObjectName(QStringLiteral("SJFButton"));
        SJFButton->setGeometry(QRect(150, 140, 40, 17));
        FIFOButton = new QRadioButton(ProcessSchedulerDialog);
        FIFOButton->setObjectName(QStringLiteral("FIFOButton"));
        FIFOButton->setGeometry(QRect(150, 160, 47, 17));
        FPPSButton = new QRadioButton(ProcessSchedulerDialog);
        FPPSButton->setObjectName(QStringLiteral("FPPSButton"));
        FPPSButton->setGeometry(QRect(150, 200, 47, 17));
        RRButton = new QRadioButton(ProcessSchedulerDialog);
        RRButton->setObjectName(QStringLiteral("RRButton"));
        RRButton->setGeometry(QRect(150, 220, 37, 17));
        runningLabel = new QLabel(ProcessSchedulerDialog);
        runningLabel->setObjectName(QStringLiteral("runningLabel"));
        runningLabel->setGeometry(QRect(140, 10, 46, 13));
        STCFButton = new QRadioButton(ProcessSchedulerDialog);
        STCFButton->setObjectName(QStringLiteral("STCFButton"));
        STCFButton->setGeometry(QRect(150, 180, 48, 17));
        label_4 = new QLabel(ProcessSchedulerDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 60, 73, 13));
        quantumBox = new QSpinBox(ProcessSchedulerDialog);
        quantumBox->setObjectName(QStringLiteral("quantumBox"));
        quantumBox->setGeometry(QRect(110, 60, 42, 22));
        quantumBox->setMinimum(5);
        quantumBox->setMaximum(30);

        retranslateUi(ProcessSchedulerDialog);

        QMetaObject::connectSlotsByName(ProcessSchedulerDialog);
    } // setupUi

    void retranslateUi(QDialog *ProcessSchedulerDialog)
    {
        ProcessSchedulerDialog->setWindowTitle(QApplication::translate("ProcessSchedulerDialog", "Dialog", 0));
        label->setText(QApplication::translate("ProcessSchedulerDialog", "Filename:", 0));
        loadButton->setText(QApplication::translate("ProcessSchedulerDialog", "Load", 0));
        label_2->setText(QApplication::translate("ProcessSchedulerDialog", "Ready Queue:", 0));
        startButton->setText(QApplication::translate("ProcessSchedulerDialog", "Start Sim", 0));
        label_3->setText(QApplication::translate("ProcessSchedulerDialog", "Completed Processes:", 0));
        SJFButton->setText(QApplication::translate("ProcessSchedulerDialog", "SJF", 0));
        FIFOButton->setText(QApplication::translate("ProcessSchedulerDialog", "FIFO", 0));
        FPPSButton->setText(QApplication::translate("ProcessSchedulerDialog", "FPPS", 0));
        RRButton->setText(QApplication::translate("ProcessSchedulerDialog", "RR", 0));
        runningLabel->setText(QString());
        STCFButton->setText(QApplication::translate("ProcessSchedulerDialog", "STCF", 0));
        label_4->setText(QApplication::translate("ProcessSchedulerDialog", "Time Quantum:", 0));
    } // retranslateUi

};

namespace Ui {
    class ProcessSchedulerDialog: public Ui_ProcessSchedulerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSSCHEDULERDIALOG_H
