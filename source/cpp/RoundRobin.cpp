#include "../headers/RoundRobin.h"

void RoundRobin::preemptCurrentProcess() {
    currentProcess->preempt();
    currentProcess->setContext(workingContext);
    readyList.push_back(currentProcess);
}

void RoundRobin::scheduleProcess(Process *process) {
    currentProcess = process;
    workingContext = currentProcess->getContext();
    currentProcess->schedule();
}

void RoundRobin::finalizeProcess(Process *process) {
    process->finalize(time);
    processesStats.push_back(process->getStats());
}

void RoundRobin::scheduleNextProcess() {
    scheduleProcess(readyList.front());
    readyList.pop_front();
}

void RoundRobin::verifyProcessesToCreate() {
    for (auto &process: this->processes) {
        if (process->getStartTime() == this->time) {
            process->create();
            this->readyList.push_back(process);
        }
    }
}

void RoundRobin::printTimelineHeader() {
    Scheduler::printTimelineHeader();
}

void RoundRobin::printTimeline() {
    Scheduler::printTimeline();
}

void RoundRobin::printProcessesStats() {
    Scheduler::printProcessesStats();
}

void RoundRobin::runScheduler() {
    printTimelineHeader();
    verifyProcessesToCreate();
    while (processes.size() != processesStats.size()) {
        if (readyList.empty()) {
            printTimeline();
            time++;
            verifyProcessesToCreate();
            continue;
        }
        scheduleNextProcess();
        for (int i = 0; i < quantum; ++i) {
            if (time != 0) verifyProcessesToCreate();
            if (currentProcess->isOver()) {
                break;
            }
            currentProcess->schedule();
            currentProcess->run();
            printTimeline();
            time++;
        }
        if (!currentProcess->isOver()) {
            preemptCurrentProcess();
        } else {
            finalizeProcess(currentProcess);
        }
    }
    printProcessesStats();
}
