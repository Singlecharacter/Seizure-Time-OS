#ifndef PCB_H
#define PCB_H

#include <QString>

enum ProcessClass
{
    Application,
    System
};

enum ProcessState
{
    Running,
    Ready,
    Blocked
};

enum SuspendedState
{
    Suspended,
    NotSuspended
};

class PCB
{
public:

    PCB();
    ~PCB();

    QString getName();
    void setName(QString newName = "");

    ProcessClass getClass();
    void setClass(ProcessClass newClass = Application);

    int getPriority();
    void setPriority(int newPriority = 0);

    ProcessState getRunState();
    void setRunState(ProcessState newState = Ready);

    SuspendedState getSuspendState();
    void setSuspendState(SuspendedState newState = NotSuspended);

    int getRequiredMemory();
    void setRequiredMemory(int newMemory = 0);

    int getTimeRemaining();
    void setTimeRemaining(int newTime = 0);

    int getTimeOfArrival();
    void setTimeOfArrival(int newTime = 0);

    int getCPUPercentage();
    void setCPUPercentage(int newPercentage = 0);

private:

    QString name;
    ProcessClass myClass;
    int priority;
    ProcessState runState;
    SuspendedState suspendState;
    int requiredMemory;
    int timeRemaining;
    int timeOfArrival;
    int CPUPercentage;
};

#endif // PCB_H
