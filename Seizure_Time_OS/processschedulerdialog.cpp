#include "processschedulerdialog.h"
#include "ui_processschedulerdialog.h"

ProcessSchedulerDialog::ProcessSchedulerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProcessSchedulerDialog)
{
    ui->setupUi(this);
}

ProcessSchedulerDialog::~ProcessSchedulerDialog()
{
    delete ui;
}
