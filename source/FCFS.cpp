//
// Created by ismael on 31/08/23.
//

#include "FCFS.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include "Process.h"

void FCFS::verifyProcessesToCreate() {
    for (const auto &process: processes) {
        if (process->getStartTime() == time) {
            process->create();
            readyQueue.push(process);
        }
    }
}

FCFS::FCFS(std::vector<Process *> processes) {
    this->processes = processes;
}


void FCFS::initialize() {
    if (!readyQueue.empty()) {
        currentProcess = readyQueue.front();
        readyQueue.pop();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
    }
    state = RUNNING;
}

void FCFS::run() {
    currentProcess->run();
    if (currentProcess->running()) {
        return;
    }
    currentProcess->finalize(time);
    processesStats.push_back(currentProcess->getStats());
    if (!readyQueue.empty()) {
        currentProcess = readyQueue.front();
        readyQueue.pop();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
    } else {
        state = FINISHED;
    }
}

void FCFS::runScheduler() {
    Scheduler::runScheduler();
}

void FCFS::printTimelineHeader() {
    Scheduler::printTimelineHeader();
}

void FCFS::printTimeline() {
    Scheduler::printTimeline();
}

void FCFS::printProcessesStats() {
    Scheduler::printProcessesStats();
}
