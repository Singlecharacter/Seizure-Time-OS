#ifndef PROCESSSCHEDULER_H
#define PROCESSSCHEDULER_H

#include <QTimer>
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "pcb.h"
#include "globals.h"

enum ScheduleType
{
    NONE,
    SJF,
    FIFO,
    STCF,
    FPPS,
    RR
};

class ProcessScheduler
{

public:

    ProcessScheduler();
    ~ProcessScheduler();

    void sortQueue(ScheduleType type);
    void processTimeout();

    bool currentlyRunning;
    ScheduleType currentType;
    QStringList completedProcesses;

    QString getRunningName();

private:

    PCB *runningProcess;
    QTimer *processTimer;

};

#endif // PROCESSSCHEDULER_H
