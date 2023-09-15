//
// Created by novais 10/09/23.
//

#include "PSP.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "Process.h"

bool PSP::comparePriority(Process* a, Process* b){
    return a->getPriority() < b->getPriority();
}

void PSP::verifyProcessesToCreate() {
    for (const auto &process: processes) {
        if (process->getStartTime() == time) {
            process->create();
            readyList.push_front(process);
            readyList.sort(comparePriority);
        }
    }
}

PSP::PSP(std::vector<Process *> processes) {
    this->processes = processes;
}


void PSP::initialize() {
    if (!readyList.empty()) {
        currentProcess = readyList.front();
        readyList.pop_front();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
    }
    state = RUNNING;
}

void PSP::run() {
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

void PSP::runScheduler() {
    Scheduler::runScheduler();
}

void PSP::printTimelineHeader() {
    Scheduler::printTimelineHeader();
}

void PSP::printTimeline() {
    Scheduler::printTimeline();
}

void PSP::printProcessesStats() {
    Scheduler::printProcessesStats();
}