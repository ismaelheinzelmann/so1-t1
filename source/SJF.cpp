//
// Created by ismael on 31/08/23.
//

#include "SJF.h"
#include <list>
#include <iostream>
#include <iomanip>
#include "Process.h"

bool compareDuration(Process* a, Process* b){
    return a->getDuration() < b->getDuration();
}

void SJF::verifyProcessesToCreate() {
    for (const auto &process: processes) {
        if (process->getStartTime() == time) {
            process->create();
            // readyList.insert(std::lower_bound(readyList.begin(), readyList.end(), process, compareDuration), process);
            readyList.push_front(process);
            readyList.sort(compareDuration);
        }
    }
}

SJF::SJF(std::vector<Process *> processes) {
    this->processes = processes;
}


void SJF::initialize() {
    if (!readyList.empty()) {
        currentProcess = readyList.front();
        readyList.pop_front();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
    }
    state = RUNNING;
}

void SJF::run() {
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

void SJF::runScheduler() {
    Scheduler::runScheduler();
}

void SJF::printTimelineHeader() {
    Scheduler::printTimelineHeader();
}

void SJF::printTimeline() {
    Scheduler::printTimeline();
}

void SJF::printProcessesStats() {
    Scheduler::printProcessesStats();
}
