/********************************************************************************
** Form generated from reading UI file 'pcbmanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCBMANAGERDIALOG_H
#define UI_PCBMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PCBManagerDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *editNameLabel;
    QLineEdit *editNameEdit;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *editPriorityLabel;
    QSpinBox *editPriorityBox;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *changePriorityButton;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *suspendButton;
    QPushButton *resumeButton;
    QPushButton *showButton;

    void setupUi(QDialog *PCBManagerDialog)
    {
        if (PCBManagerDialog->objectName().isEmpty())
            PCBManagerDialog->setObjectName(QStringLiteral("PCBManagerDialog"));
        PCBManagerDialog->resize(195, 171);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PCBManagerDialog->sizePolicy().hasHeightForWidth());
        PCBManagerDialog->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(PCBManagerDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 174, 147));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        editNameLabel = new QLabel(layoutWidget);
        editNameLabel->setObjectName(QStringLiteral("editNameLabel"));

        horizontalLayout_4->addWidget(editNameLabel);

        editNameEdit = new QLineEdit(layoutWidget);
        editNameEdit->setObjectName(QStringLiteral("editNameEdit"));

        horizontalLayout_4->addWidget(editNameEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        editPriorityLabel = new QLabel(layoutWidget);
        editPriorityLabel->setObjectName(QStringLiteral("editPriorityLabel"));

        horizontalLayout_8->addWidget(editPriorityLabel);

        editPriorityBox = new QSpinBox(layoutWidget);
        editPriorityBox->setObjectName(QStringLiteral("editPriorityBox"));
        editPriorityBox->setMinimum(-127);
        editPriorityBox->setMaximum(128);

        horizontalLayout_8->addWidget(editPriorityBox);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        changePriorityButton = new QPushButton(layoutWidget);
        changePriorityButton->setObjectName(QStringLiteral("changePriorityButton"));

        horizontalLayout_9->addWidget(changePriorityButton);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_9);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        suspendButton = new QPushButton(layoutWidget);
        suspendButton->setObjectName(QStringLiteral("suspendButton"));

        horizontalLayout_7->addWidget(suspendButton);

        resumeButton = new QPushButton(layoutWidget);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));

        horizontalLayout_7->addWidget(resumeButton);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_3);

        showButton = new QPushButton(layoutWidget);
        showButton->setObjectName(QStringLiteral("showButton"));

        verticalLayout_4->addWidget(showButton);


        retranslateUi(PCBManagerDialog);

        QMetaObject::connectSlotsByName(PCBManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *PCBManagerDialog)
    {
        PCBManagerDialog->setWindowTitle(QApplication::translate("PCBManagerDialog", "PCB Manager", 0));
        editNameLabel->setText(QApplication::translate("PCBManagerDialog", "Name:", 0));
        editPriorityLabel->setText(QApplication::translate("PCBManagerDialog", "Priority:", 0));
        changePriorityButton->setText(QApplication::translate("PCBManagerDialog", "Change Priority", 0));
        suspendButton->setText(QApplication::translate("PCBManagerDialog", "Suspend", 0));
        resumeButton->setText(QApplication::translate("PCBManagerDialog", "Resume", 0));
        showButton->setText(QApplication::translate("PCBManagerDialog", "Show PCBs", 0));
    } // retranslateUi

};

namespace Ui {
    class PCBManagerDialog: public Ui_PCBManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCBMANAGERDIALOG_H
