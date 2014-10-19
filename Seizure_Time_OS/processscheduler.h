#ifndef PROCESSSCHEDULER_H
#define PROCESSSCHEDULER_H

#include <QTimer>
#include <QWidget>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "pcb.h"
#include "globals.h"
#include "memorymanager.h"

enum ScheduleType
{
    NONE,
    SJF,
    FIFO,
    STCF,
    FPPS,
    RR,
    MLFQ,
    LS
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
    int systemTime;
    int timeQuantumSize;
    int currentTimeQuantum;
    int totalTurnaroundTime;
    QFile f;
    QTextStream fout;

    QString getRunningName();

    void setupIncomplete();

private:

    PCB *runningProcess;
    QTimer *processTimer;

    MemoryManager manager;
};

#endif // PROCESSSCHEDULER_H
