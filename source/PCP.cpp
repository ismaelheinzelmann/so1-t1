//
// Created by novais 10/09/23.
//

#include "PCP.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "Process.h"

bool comparePriority(Process* a, Process* b){
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

PCP::PCP(std::vector<Process *> processes) {
    this->processes = processes;
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
    currentProcess->run();
    if (currentProcess->running()) {
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
