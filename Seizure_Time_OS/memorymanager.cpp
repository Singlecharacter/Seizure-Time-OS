#include "memorymanager.h"

MemoryManager::MemoryManager(int totalMemSize)
{
    memorySlot newSlot;
    newSlot.size = totalMemSize;
    newSlot.inUse = false;
    newSlot.name = "FREE";
}

MemoryManager::~MemoryManager()
{

}

bool MemoryManager::addProcess(PCB *process)
{
    if(insertProcess(process))
    {
        return true;
    }

    coalesce();
    if(insertProcess(process))
    {
        return true;
    }

    compact();
    if(insertProcess(process))
    {
        return true;
    }

    return false;
}

bool MemoryManager::removeProcess(PCB *process)
{
    QString nameToFind = process->getName();

    for(int i = 0; i < memoryTable.size(); i++)
    {
        if(memoryTable.at(i).name == nameToFind)
        {
            memoryTable.erase(memoryTable.begin()+i);
            return true;
        }
    }

    return false;
}

bool MemoryManager::insertProcess(PCB *process)
{
    //Make sure the process isn't in memory already
    for(int i = 0; i < memoryTable.size(); i++)
    {
        if(memoryTable.at(i).name == process->getName())
        {
            return false;
        }
    }

    int sizeOfMemory = process->getRequiredMemory();
    for(int i = 0; i < memoryTable.size(); i++)
    {
        memorySlot currentSlot = memoryTable.at(i);
        if(currentSlot.size >= sizeOfMemory && !currentSlot.inUse)
        {
            if(currentSlot.size != sizeOfMemory)
            {
                int temp = currentSlot.size;
                currentSlot.size = sizeOfMemory;

                memorySlot newSlot;
                newSlot.size = temp - sizeOfMemory;
                newSlot.inUse = false;
                newSlot.name = process->getName();
                memoryTable.insert(memoryTable.begin()+i+1,newSlot);
            }
            currentSlot.inUse = true;
            return true;
        }
    }

    return false;
}

void MemoryManager::coalesce()
{
    for(int i = 0; i < memoryTable.size()-1;i++)
    {
        memorySlot currentSlot = memoryTable.at(i);
        memorySlot nextSlot = memoryTable.at(i+1);

        if(!currentSlot.inUse && !nextSlot.inUse)
        {
            currentSlot.size = currentSlot.size + nextSlot.size;
            memoryTable.erase(memoryTable.begin()+i+1);
            i--;
        }
    }
}

void MemoryManager::compact()
{
    int unusedIndex = 0;
    for(int i = 0; i < memoryTable.size(); i++)
    {
        if(!memoryTable.at(i).inUse)
        {
            unusedIndex = i;
            break;
        }
    }

    for(int i = unusedIndex + 1; i < memoryTable.size(); i++)
    {
        if(!memoryTable.at(i).inUse)
        {
            memorySlot temp = memoryTable.at(unusedIndex+1);
            memoryTable.at(unusedIndex+1) = memoryTable.at(i);
            memoryTable.at(i) = temp;
            unusedIndex++;
        }
    }
}
