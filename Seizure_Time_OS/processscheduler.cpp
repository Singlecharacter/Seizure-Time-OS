#include "processscheduler.h"

ProcessScheduler::ProcessScheduler() : currentlyRunning(false), runningProcess(NULL), currentType(NONE), systemTime(0), timeQuantumSize(0),
                                       currentTimeQuantum(0)
{
    completedProcesses.clear();
}

ProcessScheduler::~ProcessScheduler()
{

}

void ProcessScheduler::processTimeout()
{
    if(currentType == NONE || (Globals().globalPCBControl.readyQueueSize() == 0 &&
                               Globals().globalPCBControl.blockedQueueSize() == 0 &&
                               runningProcess == NULL &&
                               completedProcesses.size() > 0))
    {
        if(systemTime > 0)
        {
            f.open(QIODevice::WriteOnly | QIODevice::Append);
            fout.setDevice(&f);
            float averageTurnaroundTime = totalTurnaroundTime/completedProcesses.size();

            fout << "\r\n";
            fout << "Total time to completion: " << systemTime << "\r\n";
            fout << "Average turnaround time: " << averageTurnaroundTime << "\r\n";
            fout << "List of completed processes in order: " << "\r\n";

            for(int i = 0; i < completedProcesses.size(); i++)
            {
                fout << completedProcesses.at(i) << "\r\n";
            }

            f.close();
        }

        currentlyRunning = false;
        systemTime = 0;
        totalTurnaroundTime = 0;
    }

    if(currentlyRunning)
    {
        f.open(QIODevice::WriteOnly | QIODevice::Append);
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
                    if(currentType == SJF)
                    {
                        totalTurnaroundTime += systemTime;
                    }
                    else
                    {
                        totalTurnaroundTime += systemTime - runningProcess->getTimeOfArrival();
                    }

                    fout << "Switching processes..." << "\r\n";
                    completedProcesses.push_back(runningProcess->getName());
                    sortQueue(currentType);
                    Globals().globalPCBControl.freePCB(runningProcess);
                    runningProcess = NULL;
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                    fout << "New process: " << runningProcess << "\r\n";
                }
            }
            else if(currentType == STCF)
            {
                if(runningProcess->getTimeRemaining() <= 0)
                {
                    totalTurnaroundTime += systemTime - runningProcess->getTimeOfArrival();

                    fout << "Switching processes..." << "\r\n";
                    completedProcesses.push_back(runningProcess->getName());
                    sortQueue(currentType);
                    Globals().globalPCBControl.freePCB(runningProcess);
                    runningProcess = NULL;
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                    fout << "New process: " << runningProcess << "\r\n";
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
            else if(currentType == FPPS)
            {
                if(runningProcess->getTimeRemaining() <= 0)
                {
                    totalTurnaroundTime += systemTime - runningProcess->getTimeOfArrival();

                    fout << "Switching processes..." << "\r\n";
                    completedProcesses.push_back(runningProcess->getName());
                    sortQueue(currentType);
                    Globals().globalPCBControl.freePCB(runningProcess);
                    runningProcess = NULL;
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                    fout << "New process: " << runningProcess << "\r\n";
                }
                else if(Globals().globalPCBControl.readyQueueSize() > 0)
                {
                    if(Globals().globalPCBControl.atReadyQueue(0)->getPriority() > runningProcess->getPriority())
                    {
                        PCB *temp = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(temp);
                        runningProcess->setRunState(Ready);
                        Globals().globalPCBControl.insertPCB(runningProcess);
                        runningProcess = temp;
                    }
                }
            }
            else if(currentType == RR)
            {
                if(runningProcess->getTimeRemaining() <= 0)
                {
                    totalTurnaroundTime += systemTime - runningProcess->getTimeOfArrival();

                    currentTimeQuantum = 0;
                    fout << "Switching processes..." << "\r\n";
                    completedProcesses.push_back(runningProcess->getName());
                    sortQueue(currentType);
                    Globals().globalPCBControl.freePCB(runningProcess);
                    runningProcess = NULL;
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                    fout << "New process: " << runningProcess << "\r\n";
                }
                else if(currentTimeQuantum == timeQuantumSize)
                {
                    currentTimeQuantum = 0;
                    PCB *temp = runningProcess;
                    runningProcess = NULL;
                    temp->setRunState(Blocked);
                    Globals().globalPCBControl.insertPCB(temp);
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                }
                else
                {
                    currentTimeQuantum++;
                }
            }
            else if(currentType == MLFQ)
            {
                if(runningProcess->getTimeRemaining() <= 0)
                {
                    totalTurnaroundTime += systemTime - runningProcess->getTimeOfArrival();
                    currentTimeQuantum = 0;
                    fout << "Switching processes..." << "\r\n";
                    completedProcesses.push_back(runningProcess->getName());
                    sortQueue(currentType);
                    Globals().globalPCBControl.freePCB(runningProcess);
                    runningProcess = NULL;
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                    fout << "New process: " << runningProcess << "\r\n";
                }
                else if(currentTimeQuantum == timeQuantumSize)
                {
                    currentTimeQuantum = 0;
                    PCB *temp = runningProcess;
                    runningProcess = NULL;
                    temp->setPriority(temp->getPriority()-1);
                    Globals().globalPCBControl.insertPCB(temp);
                    if(Globals().globalPCBControl.readyQueueSize() > 0)
                    {
                        runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                        Globals().globalPCBControl.removePCB(runningProcess);
                    }
                }
                else
                {
                    currentTimeQuantum++;
                }
            }
            else if(currentType == LS)
            {
                
            }
        }
        else
        {
            if(Globals().globalPCBControl.readyQueueSize() > 0)
            {
                runningProcess = Globals().globalPCBControl.atReadyQueue(0);
                fout << "Running process(new): " << runningProcess->getName() << "\r\n";
                Globals().globalPCBControl.removePCB(runningProcess);
                qDebug() << runningProcess->getName();
            }
        }

        systemTime++;
        f.close();
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
    else if(type == FPPS)
    {
        qDebug() << "Sorting for FPPS.";
        setupIncomplete();

        //Sort the ready queue by priority
        for(int j = 0; j < Globals().globalPCBControl.readyQueueSize(); j++)
        {
            for(int i = j; i < Globals().globalPCBControl.readyQueueSize();i++)
            {
                if(Globals().globalPCBControl.atReadyQueue(i)->getPriority() > Globals().globalPCBControl.atReadyQueue(j)->getPriority())
                {
                    Globals().globalPCBControl.swapReadyQueue(j,i);
                }
            }
        }
    }
    else if(type == RR)
    {
        qDebug() << "Sorting for RR.";
        setupIncomplete();

        if(Globals().globalPCBControl.readyQueueSize() == 0)
        {
            if(Globals().globalPCBControl.blockedQueueSize() > 0)
            {
                //If the ready queue is empty, move all blocked processes that have arrived back to the ready queue
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
        }
    }
    else if(type == MLFQ)
    {
        qDebug() << "Sorting for MLFQ.";
        setupIncomplete();

        //Sort the ready queue by priority
        sortQueue(FPPS);

        //Check the blocked queue to see if all processes have arrived
        if(Globals().globalPCBControl.blockedQueueSize() == 0)
        {
            //Check that all process priorities are 0
            bool zeroCheck = true;
            for(int i = 0; i < Globals().globalPCBControl.readyQueueSize(); i++)
            {
                if(Globals().globalPCBControl.atReadyQueue(i)->getPriority() != 0)
                {
                    zeroCheck = false;
                    break;
                }
            }

            if(zeroCheck)
            {
                currentType = RR;
            }
        }
    }
    else if(type == LS)
    {
        qDebug() << "Sorting for LS.";
        setupIncomplete();
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
        if(temp->getTimeOfArrival() == systemTime)
        {
            Globals().globalPCBControl.removePCB(temp);
            temp->setRunState(Ready);
            Globals().globalPCBControl.insertPCB(temp);
        }
    }
}
