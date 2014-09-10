#ifndef PCBQUEUE_H
#define PCBQUEUE_H

#include "pcb.h"

struct PCBNode
{
    PCB *containedPCB;

    PCBNode *next;
};

class PCBQueue
{
public:

    PCBQueue();
    ~PCBQueue();

    void deleteNodes();
    int getNodeCount();

    void push(PCB* pcb = NULL);
    PCB *pop();

private:

    PCBNode *head;
    PCBNode *tail;

};

#endif // PCBQUEUE_H
