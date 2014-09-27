#ifndef PROCESSSCHEDULER_H
#define PROCESSSCHEDULER_H

#include <QTimer>
#include <QWidget>
#include "pcb.h"
#include "globals.h"

enum ScheduleType
{
    NONE,
    SJF
};

class ProcessScheduler : public QWidget
{

public:

    ProcessScheduler();
    ~ProcessScheduler();

    void sortQueue(ScheduleType type);

private:

    PCB *runningProcess;
    QTimer *processTimer;
    bool currentlyRunning;
    ScheduleType currentType;

private slots:

    void processTimeout();

};

#endif // PROCESSSCHEDULER_H
