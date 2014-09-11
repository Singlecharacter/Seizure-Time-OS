#ifndef PCBMANAGERDIALOG_H
#define PCBMANAGERDIALOG_H

#include "pcb.h"
#include "pcbcontrol.h"
#include "textdialog.h"
#include "globals.h"

#include <QDialog>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>

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
    QLineEdit *createNameEdit;
    QLineEdit *editNameEdit;
    QComboBox *classCombo;
    QSpinBox *createPriorityBox;
    QSpinBox *editPriorityBox;

    QPushButton *createButton;
    QPushButton *deleteButton;
    QPushButton *blockButton;
    QPushButton *unblockButton;
    QPushButton *suspendButton;
    QPushButton *resumeButton;
    QPushButton *showButton;
    QPushButton *changePriorityButton;

    //Message dialog
    TextDialog *textDisplay;

private slots:

    void createClicked();
    void deleteClicked();
    void blockClicked();
    void unblockClicked();
    void suspendClicked();
    void resumeClicked();
    void showClicked();
    void changePriorityClicked();

};

#endif // PCBMANAGERDIALOG_H
