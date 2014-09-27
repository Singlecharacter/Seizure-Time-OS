#include "processscheduler.h"

ProcessScheduler::ProcessScheduler() : currentlyRunning(false), runningProcess(NULL), currentType(NONE)
{
    completedProcesses.clear();
}

ProcessScheduler::~ProcessScheduler()
{

}

void ProcessScheduler::processTimeout()
{
    if(currentType == NONE || (Globals().globalPCBControl.readyQueueSize() == 0 && Globals().globalPCBControl.blockedQueueSize() == 0 && runningProcess == NULL) )
    {
        currentlyRunning = false;
    }

    if(currentlyRunning)
    {
        qDebug() << "Timeout";
        if(runningProcess != NULL)
        {
            qDebug() << "Running process: " << runningProcess;
            runningProcess->setTimeRemaining(runningProcess->getTimeRemaining() - 1);

            qDebug() << runningProcess->getTimeRemaining();
            if(runningProcess->getTimeRemaining() <= 0)
            {
                qDebug() << "Switching processes...";
                completedProcesses.push_back(runningProcess->getName());
                sortQueue(currentType);
                Globals().globalPCBControl.freePCB(runningProcess);
                runningProcess = NULL;
                if(Globals().globalPCBControl.readyQueueSize() > 0)
                {
                    runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                    Globals().globalPCBControl.removePCB(runningProcess);
                }
                qDebug() << "New process: " << runningProcess;
            }
        }
        else
        {
            if(Globals().globalPCBControl.readyQueueSize() > 0)
            {
                runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                qDebug() << "Running process(new): " << runningProcess;
                Globals().globalPCBControl.removePCB(runningProcess);
                qDebug() << runningProcess->getName();
            }
        }
    }
}

void ProcessScheduler::sortQueue(ScheduleType type)
{
    if(type == SJF)
    {
        //All processes are in the ready queue, so sort the ready queue by time remaining

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

QString ProcessScheduler::getRunningName()
{
    if(runningProcess == NULL)
    {
        return "NONE";
    }
    return runningProcess->getName();
}
