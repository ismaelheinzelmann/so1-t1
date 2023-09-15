//
// Created by novais 10/09/23.
//

#include "../headers/PCP.h"
#include <iostream>

bool PCP::comparePriority(Process* a, Process* b){
    return a->getPriority() < b->getPriority();
}

void PCP::verifyProcessesToCreate() {
    for (const auto &process: processes) {
        if (process->getStartTime() == time) {
            process->create();
            readyList.push_front(process);
            readyList.sort(comparePriority);
        }
    }
}

void PCP::initialize() {
    if (!readyList.empty()) {
        currentProcess = readyList.front();
        readyList.pop_front();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
    }
    state = RUNNING;
}

void PCP::run() {
    std::cout<<"TIME "<<time<<std::endl;
    currentProcess->run();
    if (currentProcess->isRunning()) {
        return;
    }
    currentProcess->finalize(time);
    processesStats.push_back(currentProcess->getStats());
    if (!readyList.empty()) {
        currentProcess = readyList.front();
        readyList.pop_front();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
    } else {
        state = FINISHED;
    }
}

void PCP::runScheduler() {
    Scheduler::runScheduler();
}

void PCP::printTimelineHeader() {
    Scheduler::printTimelineHeader();
}

void PCP::printTimeline() {
    Scheduler::printTimeline();
}

void PCP::printProcessesStats() {
    Scheduler::printProcessesStats();
}
