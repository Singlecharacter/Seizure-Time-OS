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
    temp->next = NULL;
    PCBNode *traverse = head;
    if(traverse == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        while(traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse->next = temp;
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

    PCB *tempPCB = temp->containedPCB;
    delete temp;
    return tempPCB;
}

PCB *PCBQueue::at(int index)
{
    PCBNode *traverse = head;
    int currentIndex = 0;
    while(traverse != NULL)
    {
        if(currentIndex == index)
        {
            return traverse->containedPCB;
        }
        currentIndex++;
        traverse = traverse->next;
    }

    return NULL;
}

void PCBQueue::remove(QString findName)
{
    qDebug() << "Entering remove";
    PCBNode *traverse = head;
    if(head != NULL)
    {
        if(head->containedPCB->getName() == findName)
        {
            head = head->next;
            delete traverse;
        }
    }

    while(traverse != NULL)
    {
        qDebug() << "Traversing..." << traverse;
        if(traverse->next == NULL)
        {
            break;
        }
        else
        {
            if(traverse->next->containedPCB->getName() == findName)
            {
                qDebug() << "Removing node..." << traverse->next;
                traverse->next = traverse->next->next;
                qDebug() << "Node removed.";
            }
        }
        traverse = traverse->next;
    }
}

void PCBQueue::swap(int index1, int index2)
{
    if(index1 < index2)
    {
        qDebug() << "Starting swap.";
        PCB *temp1 = at(index1);
        PCB *temp2 = at(index2);

        PCBNode *traverse = head;
        PCBNode *firstHolder = NULL;

        int traverseIndex = 0;
        while(traverse != NULL)
        {
            if(traverseIndex == index1)
            {
                firstHolder = traverse;
                qDebug() << "Found index 1";
            }
            else if(traverseIndex == index2)
            {
                qDebug() << "Found index 2";

                qDebug() << traverse->containedPCB;
                qDebug() << firstHolder->containedPCB;

                traverse->containedPCB = temp1;
                firstHolder->containedPCB = temp2;

                qDebug() << traverse->containedPCB;
                qDebug() << firstHolder->containedPCB;
                break;
            }
            traverse = traverse->next;
            traverseIndex++;
        }
    }
}

PCB *PCBQueue::find(QString findName)
{
    PCBNode *traverse = head;
    while(traverse != NULL)
    {
        if(traverse->containedPCB->getName() == findName)
        {
            return traverse->containedPCB;
        }
        traverse = traverse->next;
    }
    return NULL;
}
