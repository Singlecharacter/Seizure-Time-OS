#ifndef PROCESSSCHEDULERDIALOG_H
#define PROCESSSCHEDULERDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QRadioButton>
#include <QDir>
#include <QTimer>
#include <QLabel>

#include "globals.h"
#include "processscheduler.h"

namespace Ui {
class ProcessSchedulerDialog;
}

class ProcessSchedulerDialog : public QDialog
{
    Q_OBJECT

public:

    explicit ProcessSchedulerDialog(QWidget *parent = 0);
    ~ProcessSchedulerDialog();

private:

    QTimer *processTimer;
    Ui::ProcessSchedulerDialog *ui;

    QTextEdit *readyQueueDisplay;
    QTextEdit *completedDisplay;
    QLineEdit *filenameEdit;
    QLabel *runningLabel;

    ProcessScheduler scheduler;

    void printReady();
    void printCompleted();

private slots:

    void SJFClicked();
    void FIFOClicked();
    void STCFClicked();
    void FPPSClicked();
    void RRClicked();
    void loadClicked();
    void startClicked();
    void processTimeout();
};

#endif // PROCESSSCHEDULERDIALOG_H
