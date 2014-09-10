#include "pcbqueue.h"

PCBQueue::PCBQueue() : head(NULL), tail(NULL)
{

}

PCBQueue::~PCBQueue()
{
    deleteNodes();
}

void PCBQueue::deleteNodes()
{
    PCBNode *temp = NULL;
    PCBNode *next = NULL;

    temp = head;
    while(temp != NULL)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
    tail = NULL;
}

int PCBQueue::getNodeCount()
{
    int nodeCount = 0;
    PCBNode *temp = head;
    while(temp != NULL)
    {
        nodeCount++;
        temp = temp->next;
    }

    return nodeCount;
}

void PCBQueue::push(PCB* pcb)
{
    PCBNode *temp = new PCBNode;
    temp->containedPCB = pcb;
    temp->next = head;
    head = temp;

    if(tail == NULL)
    {
        tail = head;
    }
}

PCB *PCBQueue::pop()
{
    PCBNode *temp = head;
    head = head->next;
    if(head == NULL)
    {
        tail = NULL;
    }

    return temp->containedPCB;
}
