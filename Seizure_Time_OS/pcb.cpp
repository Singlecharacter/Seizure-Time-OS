#include "pcb.h"

PCB::PCB() : name(""), myClass(Application), priority(0), runState(Ready), suspendState(NotSuspended), requiredMemory(0)
{

}

PCB::~PCB()
{

}

QString PCB::getName()
{
    return name;
}

void PCB::setName(QString newName)
{
    name = newName;
}

ProcessClass PCB::getClass()
{
    return myClass;
}

void PCB::setClass(ProcessClass newClass)
{
    myClass = newClass;
}

int PCB::getPriority()
{
    return priority;
}

void PCB::setPriority(int newPriority)
{
    priority = newPriority;
}

ProcessState PCB::getRunState()
{
    return runState;
}

void PCB::setRunState(ProcessState newState)
{
    runState = newState;
}

SuspendedState PCB::getSuspendState()
{
    return suspendState;
}

void PCB::setSuspendState(SuspendedState newState)
{
    suspendState = newState;
}

int PCB::getRequiredMemory()
{
    return requiredMemory;
}

void PCB::setRequiredMemory(int newMemory)
{
    requiredMemory = newMemory;
}
