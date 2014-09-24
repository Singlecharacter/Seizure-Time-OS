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

QT_BEGIN_NAMESPACE

class Ui_ProcessSchedulerDialog
{
public:

    void setupUi(QDialog *ProcessSchedulerDialog)
    {
        if (ProcessSchedulerDialog->objectName().isEmpty())
            ProcessSchedulerDialog->setObjectName(QStringLiteral("ProcessSchedulerDialog"));
        ProcessSchedulerDialog->resize(400, 300);

        retranslateUi(ProcessSchedulerDialog);

        QMetaObject::connectSlotsByName(ProcessSchedulerDialog);
    } // setupUi

    void retranslateUi(QDialog *ProcessSchedulerDialog)
    {
        ProcessSchedulerDialog->setWindowTitle(QApplication::translate("ProcessSchedulerDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ProcessSchedulerDialog: public Ui_ProcessSchedulerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSSCHEDULERDIALOG_H
