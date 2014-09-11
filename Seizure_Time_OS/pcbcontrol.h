#ifndef PCBCONTROL_H
#define PCBCONTROL_H

#include <QString>

#include "pcb.h"
#include "pcbqueue.h"

class PCBControl
{
public:

    PCBControl();
    ~PCBControl();

    PCB *allocatePCB();
    void freePCB(PCB *PCBToDelete = NULL);
    PCB *setupPCB(QString name = "",int priority = 0,ProcessClass myClass = Application);
    PCB *findPCB(QString name = "");
    void insertPCB(PCB *PCBToInsert = NULL);
    void removePCB(PCB *PCBToRemove = NULL);

private:

    PCBQueue readyQueue;
    PCBQueue blockedQueue;

};

#endif // PCBCONTROL_H
