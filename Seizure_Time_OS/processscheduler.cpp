#include "processscheduler.h"

ProcessScheduler::ProcessScheduler() : currentlyRunning(false), runningProcess(NULL), currentType(NONE), systemTime(0)
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
        systemTime = 0;
    }

    if(currentlyRunning)
    {
        systemTime++;
        qDebug() << "Timeout";
        sortQueue(currentType);

        if(runningProcess != NULL)
        {
            qDebug() << "Running process: " << runningProcess;
            runningProcess->setTimeRemaining(runningProcess->getTimeRemaining() - 1);

            qDebug() << runningProcess->getTimeRemaining();

            if(currentType == SJF || currentType == FIFO)
            {
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
            else if(currentType == STCF)
            {
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
                else if(Globals().globalPCBControl.readyQueueSize() > 0)
                {
                    if(Globals().globalPCBControl.atReadyQueue(0)->getTimeRemaining() < runningProcess->getTimeRemaining())
                    {
                        PCB *temp = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(temp);
                        runningProcess->setRunState(Ready);
                        Globals().globalPCBControl.insertPCB(runningProcess);
                        runningProcess = temp;
                    }
                }
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
    else if(type == FIFO)
    {
        qDebug() << "Sorting for FIFO.";
        setupIncomplete();

        //Sort the ready queue by time of arrival
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
    else if(type == STCF)
    {
        qDebug() << "Sorting for STCF.";
        setupIncomplete();

        //Sort the ready queue by time remaining
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

void ProcessScheduler::setupIncomplete()
{
    //Move processes that haven't yet arrived to the blocked queue
    for(int i = 0; i < Globals().globalPCBControl.readyQueueSize(); i++)
    {
        PCB *temp = Globals().globalPCBControl.atReadyQueue(i);
        qDebug() << "Temp's time of arrival: " << temp->getTimeOfArrival();
        qDebug() << "System time: " << systemTime;
        if(temp->getTimeOfArrival() > systemTime)
        {
            qDebug() << "Removed a process.";
            Globals().globalPCBControl.removePCB(temp);
            temp->setRunState(Blocked);
            Globals().globalPCBControl.insertPCB(temp);
            i--;
        }
    }

    //Move any newly arrived processes to the ready queue
    for(int i = 0; i < Globals().globalPCBControl.blockedQueueSize(); i++)
    {
        PCB *temp = Globals().globalPCBControl.atBlockedQueue(i);
        if(temp->getTimeOfArrival() <= systemTime)
        {
            Globals().globalPCBControl.removePCB(temp);
            temp->setRunState(Ready);
            Globals().globalPCBControl.insertPCB(temp);
        }
    }
}
