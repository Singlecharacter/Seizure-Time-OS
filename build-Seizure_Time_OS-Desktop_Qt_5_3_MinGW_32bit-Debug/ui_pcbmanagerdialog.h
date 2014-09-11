/********************************************************************************
** Form generated from reading UI file 'pcbmanagerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCBMANAGERDIALOG_H
#define UI_PCBMANAGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
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
    QGroupBox *createBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *createNameLabel;
    QLineEdit *createNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *classLabel;
    QComboBox *classCombo;
    QHBoxLayout *horizontalLayout_3;
    QLabel *createPriorityLabel;
    QSpinBox *createPriorityBox;
    QPushButton *createButton;
    QPushButton *showButton;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *editNameLabel;
    QLineEdit *editNameEdit;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteButton;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *blockButton;
    QPushButton *unblockButton;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *suspendButton;
    QPushButton *resumeButton;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *editPriorityLabel;
    QSpinBox *editPriorityBox;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *changePriorityButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *PCBManagerDialog)
    {
        if (PCBManagerDialog->objectName().isEmpty())
            PCBManagerDialog->setObjectName(QStringLiteral("PCBManagerDialog"));
        PCBManagerDialog->resize(400, 300);
        createBox = new QGroupBox(PCBManagerDialog);
        createBox->setObjectName(QStringLiteral("createBox"));
        createBox->setGeometry(QRect(10, 10, 196, 131));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(createBox->sizePolicy().hasHeightForWidth());
        createBox->setSizePolicy(sizePolicy);
        widget = new QWidget(createBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 176, 111));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        createNameLabel = new QLabel(widget);
        createNameLabel->setObjectName(QStringLiteral("createNameLabel"));

        horizontalLayout->addWidget(createNameLabel);

        createNameEdit = new QLineEdit(widget);
        createNameEdit->setObjectName(QStringLiteral("createNameEdit"));

        horizontalLayout->addWidget(createNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        classLabel = new QLabel(widget);
        classLabel->setObjectName(QStringLiteral("classLabel"));

        horizontalLayout_2->addWidget(classLabel);

        classCombo = new QComboBox(widget);
        classCombo->setObjectName(QStringLiteral("classCombo"));
        classCombo->setEditable(false);

        horizontalLayout_2->addWidget(classCombo);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        createPriorityLabel = new QLabel(widget);
        createPriorityLabel->setObjectName(QStringLiteral("createPriorityLabel"));

        horizontalLayout_3->addWidget(createPriorityLabel);

        createPriorityBox = new QSpinBox(widget);
        createPriorityBox->setObjectName(QStringLiteral("createPriorityBox"));
        createPriorityBox->setMinimum(-127);
        createPriorityBox->setMaximum(128);

        horizontalLayout_3->addWidget(createPriorityBox);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        createButton = new QPushButton(widget);
        createButton->setObjectName(QStringLiteral("createButton"));

        verticalLayout_2->addWidget(createButton);

        showButton = new QPushButton(PCBManagerDialog);
        showButton->setObjectName(QStringLiteral("showButton"));
        showButton->setGeometry(QRect(270, 30, 75, 23));
        widget1 = new QWidget(PCBManagerDialog);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 150, 174, 119));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        editNameLabel = new QLabel(widget1);
        editNameLabel->setObjectName(QStringLiteral("editNameLabel"));

        horizontalLayout_4->addWidget(editNameLabel);

        editNameEdit = new QLineEdit(widget1);
        editNameEdit->setObjectName(QStringLiteral("editNameEdit"));

        horizontalLayout_4->addWidget(editNameEdit);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        deleteButton = new QPushButton(widget1);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_5->addWidget(deleteButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        blockButton = new QPushButton(widget1);
        blockButton->setObjectName(QStringLiteral("blockButton"));

        horizontalLayout_6->addWidget(blockButton);

        unblockButton = new QPushButton(widget1);
        unblockButton->setObjectName(QStringLiteral("unblockButton"));

        horizontalLayout_6->addWidget(unblockButton);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        suspendButton = new QPushButton(widget1);
        suspendButton->setObjectName(QStringLiteral("suspendButton"));

        horizontalLayout_7->addWidget(suspendButton);

        resumeButton = new QPushButton(widget1);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));

        horizontalLayout_7->addWidget(resumeButton);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_3);

        widget2 = new QWidget(PCBManagerDialog);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(240, 150, 127, 55));
        verticalLayout_5 = new QVBoxLayout(widget2);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        editPriorityLabel = new QLabel(widget2);
        editPriorityLabel->setObjectName(QStringLiteral("editPriorityLabel"));

        horizontalLayout_8->addWidget(editPriorityLabel);

        editPriorityBox = new QSpinBox(widget2);
        editPriorityBox->setObjectName(QStringLiteral("editPriorityBox"));
        editPriorityBox->setMinimum(-127);
        editPriorityBox->setMaximum(128);

        horizontalLayout_8->addWidget(editPriorityBox);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        changePriorityButton = new QPushButton(widget2);
        changePriorityButton->setObjectName(QStringLiteral("changePriorityButton"));

        horizontalLayout_9->addWidget(changePriorityButton);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_9);

        createBox->raise();
        editNameEdit->raise();
        editNameLabel->raise();
        deleteButton->raise();
        blockButton->raise();
        unblockButton->raise();
        suspendButton->raise();
        resumeButton->raise();
        changePriorityButton->raise();
        unblockButton->raise();
        editPriorityLabel->raise();
        editPriorityBox->raise();
        showButton->raise();

        retranslateUi(PCBManagerDialog);

        classCombo->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(PCBManagerDialog);
    } // setupUi

    void retranslateUi(QDialog *PCBManagerDialog)
    {
        PCBManagerDialog->setWindowTitle(QApplication::translate("PCBManagerDialog", "Dialog", 0));
        createBox->setTitle(QString());
        createNameLabel->setText(QApplication::translate("PCBManagerDialog", "Name:", 0));
        classLabel->setText(QApplication::translate("PCBManagerDialog", "Class:", 0));
        classCombo->setCurrentText(QString());
        createPriorityLabel->setText(QApplication::translate("PCBManagerDialog", "Priority:", 0));
        createButton->setText(QApplication::translate("PCBManagerDialog", "Create PCB", 0));
        showButton->setText(QApplication::translate("PCBManagerDialog", "Show PCBs", 0));
        editNameLabel->setText(QApplication::translate("PCBManagerDialog", "Name:", 0));
        deleteButton->setText(QApplication::translate("PCBManagerDialog", "Delete", 0));
        blockButton->setText(QApplication::translate("PCBManagerDialog", "Block", 0));
        unblockButton->setText(QApplication::translate("PCBManagerDialog", "Unblock", 0));
        suspendButton->setText(QApplication::translate("PCBManagerDialog", "Suspend", 0));
        resumeButton->setText(QApplication::translate("PCBManagerDialog", "Resume", 0));
        editPriorityLabel->setText(QApplication::translate("PCBManagerDialog", "Priority:", 0));
        changePriorityButton->setText(QApplication::translate("PCBManagerDialog", "Change Priority", 0));
    } // retranslateUi

};

namespace Ui {
    class PCBManagerDialog: public Ui_PCBManagerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCBMANAGERDIALOG_H
