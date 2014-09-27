#ifndef PROCESSSCHEDULERDIALOG_H
#define PROCESSSCHEDULERDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QDir>

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

    Ui::ProcessSchedulerDialog *ui;

    QTextEdit *readyQueueDisplay;
    QLineEdit *filenameEdit;
    QPushButton *SJFButton;
    QPushButton *loadButton;

    ProcessScheduler scheduler;

    void printReady();

private slots:

    void SJFClicked();
    void loadClicked();
};

#endif // PROCESSSCHEDULERDIALOG_H
