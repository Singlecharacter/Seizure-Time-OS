/********************************************************************************
** Form generated from reading UI file 'processschedulerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
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
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ProcessSchedulerDialog
{
public:
    QPushButton *SJFButton;
    QLineEdit *filenameEdit;
    QLabel *label;
    QPushButton *loadButton;
    QTextEdit *readyQueueDisplay;

    void setupUi(QDialog *ProcessSchedulerDialog)
    {
        if (ProcessSchedulerDialog->objectName().isEmpty())
            ProcessSchedulerDialog->setObjectName(QStringLiteral("ProcessSchedulerDialog"));
        ProcessSchedulerDialog->resize(400, 300);
        SJFButton = new QPushButton(ProcessSchedulerDialog);
        SJFButton->setObjectName(QStringLiteral("SJFButton"));
        SJFButton->setGeometry(QRect(150, 140, 75, 23));
        filenameEdit = new QLineEdit(ProcessSchedulerDialog);
        filenameEdit->setObjectName(QStringLiteral("filenameEdit"));
        filenameEdit->setGeometry(QRect(80, 80, 113, 20));
        label = new QLabel(ProcessSchedulerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 80, 46, 13));
        loadButton = new QPushButton(ProcessSchedulerDialog);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(200, 80, 75, 23));
        readyQueueDisplay = new QTextEdit(ProcessSchedulerDialog);
        readyQueueDisplay->setObjectName(QStringLiteral("readyQueueDisplay"));
        readyQueueDisplay->setGeometry(QRect(20, 140, 104, 141));

        retranslateUi(ProcessSchedulerDialog);

        QMetaObject::connectSlotsByName(ProcessSchedulerDialog);
    } // setupUi

    void retranslateUi(QDialog *ProcessSchedulerDialog)
    {
        ProcessSchedulerDialog->setWindowTitle(QApplication::translate("ProcessSchedulerDialog", "Dialog", 0));
        SJFButton->setText(QApplication::translate("ProcessSchedulerDialog", "SJF", 0));
        label->setText(QApplication::translate("ProcessSchedulerDialog", "Filename:", 0));
        loadButton->setText(QApplication::translate("ProcessSchedulerDialog", "Load", 0));
    } // retranslateUi

};

namespace Ui {
    class ProcessSchedulerDialog: public Ui_ProcessSchedulerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSSCHEDULERDIALOG_H
