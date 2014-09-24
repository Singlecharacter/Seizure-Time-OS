#ifndef PROCESSSCHEDULERDIALOG_H
#define PROCESSSCHEDULERDIALOG_H

#include <QDialog>

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
};

#endif // PROCESSSCHEDULERDIALOG_H
