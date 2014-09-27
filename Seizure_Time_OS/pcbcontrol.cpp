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
    if(PCBToDelete != NULL)
    {
        readyQueue.remove(PCBToDelete->getName());
        blockedQueue.remove(PCBToDelete->getName());
        delete PCBToDelete;
    }
}

PCB *PCBControl::setupPCB(QString name, int priority, ProcessClass myClass)
{
    if(findPCB(name) != NULL || priority < -127 || priority > 129)
    {
        return NULL;
    }
    else
    {
        PCB *newPCB = allocatePCB();
        newPCB->setName(name);
        newPCB->setPriority(priority);
        newPCB->setClass(myClass);
        insertPCB(newPCB);

        return newPCB;
    }
}

PCB *PCBControl::findPCB(QString name)
{
    PCB *foundPCB = NULL;
    foundPCB = readyQueue.find(name);
    /*if(foundPCB == NULL)
    {
        foundPCB = blockedQueue.find(name);
    }*/

    return foundPCB;
}

PCB *PCBControl::atReadyQueue(int index)
{
    return readyQueue.at(index);
}

PCB *PCBControl::atBlockedQueue(int index)
{
    return blockedQueue.at(index);
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

int PCBControl::readyQueueSize()
{
    return readyQueue.getNodeCount();
}

int PCBControl::blockedQueueSize()
{
    return blockedQueue.getNodeCount();
}

bool PCBControl::setupFromFile(QString fname)
{

    readyQueue.deleteNodes();
    blockedQueue.deleteNodes();

    QFile setupFile(fname);
    if(!setupFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QTextStream setupStream(&setupFile);
    while(!setupStream.atEnd())
    {
        QString line = setupStream.readLine();
        QStringList linePieces = line.split(" ");

        if(linePieces.length() == 7)
        {
            PCB *newPCB = allocatePCB();

            newPCB->setName(linePieces.at(0));

            if(linePieces.at(1) == "A")
            {
                newPCB->setClass(Application);
            }
            else
            {
                newPCB->setClass(System);
            }

            newPCB->setPriority(linePieces.at(2).toInt());
            newPCB->setRequiredMemory(linePieces.at(3).toInt());
            newPCB->setTimeRemaining(linePieces.at(4).toInt());
            newPCB->setTimeOfArrival(linePieces.at(5).toInt());
            newPCB->setCPUPercentage(linePieces.at(6).toInt());

            insertPCB(newPCB);
        }
        else
        {

            break;
        }
    }

    return true;
}

void PCBControl::swapBlockedQueue(int index1, int index2)
{
    blockedQueue.swap(index1,index2);
}

void PCBControl::swapReadyQueue(int index1, int index2)
{
    readyQueue.swap(index1,index2);
}
