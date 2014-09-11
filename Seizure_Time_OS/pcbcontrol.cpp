#include "pcbcontrol.h"

PCBControl::PCBControl()
{

}

PCBControl::~PCBControl()
{

}

PCB *PCBControl::allocatePCB()
{
    PCB *newPCB = new PCB();
    return newPCB;
}

void PCBControl::freePCB(PCB *PCBToDelete)
{
    readyQueue.remove(PCBToDelete->getName());
    blockedQueue.remove(PCBToDelete->getName());
    delete PCBToDelete;
}

PCB *PCBControl::setupPCB(QString name, int priority, ProcessClass myClass)
{
    if(findPCB(name) == NULL || priority < -127 || priority > 129)
    {
        return NULL;
    }
    else
    {
        PCB *newPCB = allocatePCB();
        newPCB->setName(name);
        newPCB->setPriority(priority);
        newPCB->setClass(myClass);

        return newPCB;
    }
}

PCB *PCBControl::findPCB(QString name)
{
    PCB *foundPCB = NULL;
    foundPCB = readyQueue.find(name);
    if(foundPCB == NULL)
    {
        foundPCB = blockedQueue.find(name);
    }

    return foundPCB;
}

void PCBControl::insertPCB(PCB *PCBToInsert)
{
    if(PCBToInsert->getRunState() == Ready)
    {
        readyQueue.push(PCBToInsert);
    }
    else
    {
        blockedQueue.push(PCBToInsert);
    }
}

void PCBControl::removePCB(PCB *PCBToRemove)
{
    readyQueue.remove(PCBToRemove->getName());
    blockedQueue.remove(PCBToRemove->getName());
}
