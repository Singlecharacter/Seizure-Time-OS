#include "processscheduler.h"

ProcessScheduler::ProcessScheduler() : currentlyRunning(false), runningProcess(NULL), currentType(NONE)
{

    processTimer = new QTimer();
    processTimer->setSingleShot(false);
    processTimer->start(1000);

    connect(processTimer,SIGNAL(timeout()),this,SLOT(processTimeout()));
}

ProcessScheduler::~ProcessScheduler()
{

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
                sortQueue(currentType);
            }
        }
    }
}

void ProcessScheduler::sortQueue(ScheduleType type)
{
    if(type == SJF)
    {
        for(int j = 0; j < Globals().globalPCBControl.readyQueueSize(); j++)
        {
            for(int i = j; i < Globals().globalPCBControl.readyQueueSize();i++)
            {
                if(Globals().globalPCBControl.atReadyQueue(i)->getTimeRemaining() < Globals().globalPCBControl.atReadyQueue(j)->getTimeRemaining())
                {
                    Globals().globalPCBControl.swapReadyQueue(j,i);
                }
            }
        }
    }
}
