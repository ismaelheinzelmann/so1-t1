//
// Created by ismael on 31/08/23.
//

#include "../headers/FCFS.h"
#include <iostream>

void FCFS::verifyProcessesToCreate() {
    for (const auto &process: processes) {
        if (process->getStartTime() == time) {
            process->create();
            readyQueue.push(process);
        }
    }
}

void FCFS::runScheduler() {
    printTimelineHeader();
    verifyProcessesToCreate();
    while (processes.size() != processesStats.size()) {
        if (readyQueue.empty()) {
            printTimeline();
            time++;
            verifyProcessesToCreate();
            continue;
        }
        currentProcess = readyQueue.front();
        readyQueue.pop();
        currentProcess->schedule();
        workingContext = currentProcess->getContext();
        for (int i = 0; i < currentProcess->getDuration(); ++i) {
            currentProcess->run();
            printTimeline();
            time++;
            verifyProcessesToCreate();
        }
        currentProcess->finalize(time);
        processesStats.push_back(currentProcess->getStats());
    }

    printProcessesStats();
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
