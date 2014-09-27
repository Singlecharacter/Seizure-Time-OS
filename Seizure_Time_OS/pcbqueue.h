#ifndef PCBQUEUE_H
#define PCBQUEUE_H

#include "pcb.h"

#include <QDebug>

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
    PCB *at(int index = 0);
    void remove(QString findName = "");
    void swap(int index1 = 0, int index2 = 0);

    PCB *find(QString findName = "");

private:

    PCBNode *head;
    PCBNode *tail;

};

#endif // PCBQUEUE_H
