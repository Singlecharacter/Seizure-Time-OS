#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "globals.h"
#include "pcb.h"

#include <vector>
#include <QString>

struct memorySlot
{
    int size;
    bool inUse;
    QString name;
};

class MemoryManager
{
public:

    MemoryManager(int totalMemSize = 1024);
    ~MemoryManager();

    bool addProcess(PCB *process);
    bool removeProcess(PCB *process);

    std::vector<memorySlot> memoryTable;

private:

    void compact();
    void coalesce();
    bool insertProcess(PCB *process);
};

#endif // MEMORYMANAGER_H
