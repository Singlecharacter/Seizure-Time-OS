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

private:

    QString name;
    ProcessClass myClass;
    int priority;
    ProcessState runState;
    SuspendedState suspendState;
    int requiredMemory;

};

#endif // PCB_H
