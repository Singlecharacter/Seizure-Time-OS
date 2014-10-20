#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include "globals.h"
#include "pcb.h"

#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>

enum MemType
{
    FIRST_FIT,
    NEXT_FIT,
    BEST_FIT,
    WORST_FIT
};

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
    bool findProcess(PCB *process);

    void logTable();

    void clearTable();

    MemType mode;

    std::vector<memorySlot*> memoryTable;

    QString fname;

private:

    void compact();
    void coalesce();
    bool insertProcess(PCB *process);

    //For next fit
    int prevIndex;

    int defaultSize;
};

#endif // MEMORYMANAGER_H
