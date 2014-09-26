#include "processscheduler.h"

ProcessScheduler::ProcessScheduler() : currentlyRunning(false), runningProcess(NULL), currentType(NONE)
{
    processTimer = new QTimer(this);
    processTimer->setSingleShot(false);
    processTimer->start(1000);

    connect(processTimer,SIGNAL(timeout()),this,SLOT(processTimeout()));
}

void ProcessScheduler::processTimeout()
{
    if(currentlyRunning)
    {
        if(runningProcess != NULL)
        {
            runningProcess->setTimeRemaining(runningProcess->getTimeRemaining() - 1);

            if(runningProcess->getTimeRemaining() <= 0)
            {
                updateQueue(currentType);
            }
        }
    }
}

void ProcessScheduler::sortQueue(ScheduleType type)
{
    if(type == SJF)
    {
        for(int j = 0; j < Globals.globalPCBControl.readyQueueSize(); j++)
        {
            PCB *temp = Globals.globalPCBControl.atReadyQueue(j);
            int tempIndex = j;
            if(temp != NULL)
            {
                for(int i = 1; i < Globals().globalPCBControl.readyQueueSize();i++)
                {
                    if(Globals().globalPCBControl.atReadyQueue(i)->getTimeRemaining() < temp->getTimeRemaining())
                    {
                        temp = Globals().globalPCBControl.atReadyQueue(i);
                        tempIndex = i;
                    }
                }

                Globals().globalPCBControl.swapReadyQueue(j,tempIndex);
            }
        }
    }
}
