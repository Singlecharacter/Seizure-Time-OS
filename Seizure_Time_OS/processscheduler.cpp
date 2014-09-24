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

void ProcessScheduler::updateQueue(ScheduleType type)
{
    Globals.globalPCBControl.freePCB(runningProcess);
    if(type == SJF)
    {
        PCB *temp = Globals.globalPCBControl.atReadyQueue(0);
        if(temp != NULL)
        {
            for(int i = 1; i < Globals().globalPCBControl.readyQueueSize();i++)
            {
                if(Globals().globalPCBControl.atReadyQueue(i)->getTimeRemaining() < temp->getTimeRemaining())
                {
                    temp = Globals().globalPCBControl.atReadyQueue(i);
                }
            }

            Globals().globalPCBControl.removePCB(temp);
        }

        runningProcess = temp;
    }
}
