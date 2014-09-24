#ifndef PCBMANAGERDIALOG_H
#define PCBMANAGERDIALOG_H

#include "pcb.h"
#include "pcbcontrol.h"
#include "textdialog.h"
#include "globals.h"
#include "multipagedialog.h"

#include <QDialog>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QStringList>

namespace Ui {
class PCBManagerDialog;
}

class PCBManagerDialog : public QDialog
{
    Q_OBJECT

public:

    explicit PCBManagerDialog(QWidget *parent = 0);
    ~PCBManagerDialog();

    void createTextDialog(QString text = "");

private:

    Ui::PCBManagerDialog *ui;

    //ui object pointers
    QLineEdit *editNameEdit;
    QSpinBox *editPriorityBox;

    QPushButton *suspendButton;
    QPushButton *resumeButton;
    QPushButton *showButton;
    QPushButton *changePriorityButton;

    //Message dialog
    TextDialog *textDisplay;

    //PCB display dialog
    MultiPageDialog *showDialog;

private slots:

    void suspendClicked();
    void resumeClicked();
    void showClicked();
    void changePriorityClicked();

};

#endif // PCBMANAGERDIALOG_H
