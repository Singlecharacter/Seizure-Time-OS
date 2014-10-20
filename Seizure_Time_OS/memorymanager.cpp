#include "memorymanager.h"

MemoryManager::MemoryManager(int totalMemSize) : fname(""), mode(FIRST_FIT), prevIndex(0)
{
    defaultSize = totalMemSize;
    memorySlot *newSlot = new memorySlot();
    newSlot->size = defaultSize;
    newSlot->inUse = false;
    newSlot->name = "FREE";

    memoryTable.push_back(newSlot);
}

MemoryManager::~MemoryManager()
{

}

bool MemoryManager::addProcess(PCB *process)
{
    if(findProcess(process))
    {
        return false;
    }

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
        if(memoryTable.at(i)->name == nameToFind)
        {
            memoryTable.at(i)->name = "FREE";
            memoryTable.at(i)->inUse = false;
            return true;
        }
    }

    return false;
}

bool MemoryManager::findProcess(PCB *process)
{
    for(int i = 0; i < memoryTable.size(); i++)
    {
        if(memoryTable.at(i)->name == process->getName())
        {
            return true;
        }
    }

    return false;
}

bool MemoryManager::insertProcess(PCB *process)
{
    //Make sure the process isn't in memory already
    if(findProcess(process))
    {
        return false;
    }

    int sizeOfMemory = process->getRequiredMemory();

    if(mode == FIRST_FIT)
    {
        for(int i = 0; i < memoryTable.size(); i++)
        {
            memorySlot *currentSlot = memoryTable.at(i);
            if(currentSlot->size >= sizeOfMemory && !currentSlot->inUse)
            {
                if(currentSlot->size != sizeOfMemory)
                {
                    int temp = currentSlot->size;
                    currentSlot->size = sizeOfMemory;

                    memorySlot *newSlot = new memorySlot();
                    newSlot->size = temp - sizeOfMemory;
                    newSlot->inUse = false;
                    newSlot->name = "FREE";
                    memoryTable.insert(memoryTable.begin()+i+1,newSlot);
                }
                currentSlot->inUse = true;
                currentSlot->name = process->getName();
                return true;
            }
        }
    }
    else if(mode == NEXT_FIT)
    {
        for(int i = prevIndex; i < memoryTable.size(); i++)
        {
            memorySlot *currentSlot = memoryTable.at(i);
            if(currentSlot->size >= sizeOfMemory && !currentSlot->inUse)
            {
                if(currentSlot->size != sizeOfMemory)
                {
                    int temp = currentSlot->size;
                    currentSlot->size = sizeOfMemory;

                    memorySlot *newSlot = new memorySlot();
                    newSlot->size = temp - sizeOfMemory;
                    newSlot->inUse = false;
                    newSlot->name = "FREE";
                    memoryTable.insert(memoryTable.begin()+i+1,newSlot);
                }
                currentSlot->inUse = true;
                currentSlot->name = process->getName();
                prevIndex = i;
                return true;
            }
        }

        for(int i = 0; i < prevIndex; i++)
        {
            memorySlot *currentSlot = memoryTable.at(i);
            if(currentSlot->size >= sizeOfMemory && !currentSlot->inUse)
            {
                if(currentSlot->size != sizeOfMemory)
                {
                    int temp = currentSlot->size;
                    currentSlot->size = sizeOfMemory;

                    memorySlot *newSlot = new memorySlot();
                    newSlot->size = temp - sizeOfMemory;
                    newSlot->inUse = false;
                    newSlot->name = "FREE";
                    memoryTable.insert(memoryTable.begin()+i+1,newSlot);
                }
                currentSlot->inUse = true;
                currentSlot->name = process->getName();
                prevIndex = i;
                return true;
            }
        }
    }
    else if(mode == BEST_FIT)
    {
        int smallestDifference = defaultSize+1;
        int smallestIndex = memoryTable.size();

        for(int i = 0; i < memoryTable.size(); i++)
        {
            if(memoryTable.at(i)->size >= sizeOfMemory && !memoryTable.at(i)->inUse)
            {
                if(memoryTable.at(i)->size - sizeOfMemory < smallestDifference)
                {
                    smallestDifference = memoryTable.at(i)->size - sizeOfMemory;
                    smallestIndex = i;
                }
            }
        }

        if(memoryTable.at(smallestIndex)->size != sizeOfMemory)
        {
            memorySlot *newSlot = new memorySlot();
            newSlot->name = "FREE";
            newSlot->inUse = false;
            newSlot->size = memoryTable.at(smallestIndex)->size - sizeOfMemory;
            memoryTable.insert(memoryTable.begin()+smallestIndex+1,newSlot);
            memoryTable.at(smallestIndex)->size = sizeOfMemory;
            memoryTable.at(smallestIndex)->name = process->getName();
            memoryTable.at(smallestIndex)->inUse = true;
        }
        else
        {
            memoryTable.at(smallestIndex)->name = process->getName();
            memoryTable.at(smallestIndex)->inUse = true;
        }
    }
    else if(mode == WORST_FIT)
    {
        int biggestDifference = defaultSize+1;
        int biggestIndex = memoryTable.size();

        for(int i = 0; i < memoryTable.size(); i++)
        {
            if(memoryTable.at(i)->size >= sizeOfMemory && !memoryTable.at(i)->inUse)
            {
                if(memoryTable.at(i)->size - sizeOfMemory > biggestDifference)
                {
                    biggestDifference = memoryTable.at(i)->size - sizeOfMemory;
                    biggestIndex = i;
                }
            }
        }

        if(memoryTable.at(biggestIndex)->size != sizeOfMemory)
        {
            memorySlot *newSlot = new memorySlot();
            newSlot->name = "FREE";
            newSlot->inUse = false;
            newSlot->size = memoryTable.at(biggestIndex)->size - sizeOfMemory;
            memoryTable.insert(memoryTable.begin()+biggestIndex+1,newSlot);
            memoryTable.at(biggestIndex)->size = sizeOfMemory;
            memoryTable.at(biggestIndex)->name = process->getName();
            memoryTable.at(biggestIndex)->inUse = true;
        }
        else
        {
            memoryTable.at(biggestIndex)->name = process->getName();
            memoryTable.at(biggestIndex)->inUse = true;
        }
    }

    return false;
}

void MemoryManager::coalesce()
{
    QFile f;
    QTextStream fout;

    f.setFileName(fname);
    f.open(QIODevice::WriteOnly | QIODevice::Append);
    fout.setDevice(&f);

    fout << "\r\n";
    fout << "Before coalescing:\r\n";

    f.close();

    logTable();
    for(int i = 0; i < memoryTable.size()-1;i++)
    {
        memorySlot *currentSlot = memoryTable.at(i);
        memorySlot *nextSlot = memoryTable.at(i+1);

        if(!currentSlot->inUse && !nextSlot->inUse)
        {
            currentSlot->size = currentSlot->size + nextSlot->size;
            memoryTable.erase(memoryTable.begin()+i+1);
            i--;
        }
    }

    f.open(QIODevice::WriteOnly | QIODevice::Append);
    fout.setDevice(&f);

    fout << "\r\nAfter coalescing:\r\n";

    f.close();

    logTable();
}

void MemoryManager::compact()
{
    QFile f;
    QTextStream fout;

    f.setFileName(fname);
    f.open(QIODevice::WriteOnly | QIODevice::Append);
    fout.setDevice(&f);

    fout << "\r\nBefore compacting:\r\n";

    f.close();

    logTable();
    int unusedIndex = 0;
    for(int i = 0; i < memoryTable.size(); i++)
    {
        if(!memoryTable.at(i)->inUse)
        {
            unusedIndex = i;
            break;
        }
    }

    for(int i = unusedIndex + 1; i < memoryTable.size(); i++)
    {
        if(!memoryTable.at(i)->inUse)
        {
            memorySlot *temp = memoryTable.at(unusedIndex+1);
            memoryTable.at(unusedIndex+1) = memoryTable.at(i);
            memoryTable.at(i) = temp;
            unusedIndex++;
        }
    }

    for(int i = 0; i < memoryTable.size()-1;i++)
    {
        memorySlot *currentSlot = memoryTable.at(i);
        memorySlot *nextSlot = memoryTable.at(i+1);

        if(!currentSlot->inUse && !nextSlot->inUse)
        {
            currentSlot->size = currentSlot->size + nextSlot->size;
            memoryTable.erase(memoryTable.begin()+i+1);
            i--;
        }
    }

    f.open(QIODevice::WriteOnly | QIODevice::Append);
    fout.setDevice(&f);

    fout << "\r\nAfter compacting:\r\n";

    f.close();

    logTable();
}

void MemoryManager::logTable()
{
    QFile f;
    QTextStream fout;

    f.setFileName(fname);
    f.open(QIODevice::WriteOnly | QIODevice::Append);
    fout.setDevice(&f);

    fout << "\r\n";
    for(int i = 0; i < memoryTable.size(); i++)
    {
        fout << memoryTable.at(i)->name << " " << memoryTable.at(i)->size << "\r\n";
    }

    fout << "\r\n";

    f.close();
}

void MemoryManager::clearTable()
{
    memoryTable.clear();

    memorySlot *newSlot = new memorySlot();
    newSlot->size = defaultSize;
    newSlot->inUse = false;
    newSlot->name = "FREE";

    memoryTable.push_back(newSlot);
}
