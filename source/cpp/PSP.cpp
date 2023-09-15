//
// Created by novais 10/09/23.
//

#include "../headers/PSP.h"
#include <utility>
#include <vector>
#include <iostream>
#include <iomanip>
#include "../headers/Process.h"

bool PSP::comparePriority(Process* a, Process* b){
    return a->getPriority() > b->getPriority();
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

void PSP::runScheduler() {
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
        for (int i = 0; i < currentProcess->getDuration(); ++i) {
            currentProcess->run();
            printTimeline();
            time++;
            verifyProcessesToCreate();
        }
        finalizeCurrentProcess();
    }
    printProcessesStats();
}

void PSP::finalizeCurrentProcess() {
    currentProcess->finalize(time);
    processesStats.push_back(currentProcess->getStats());
}

void PSP::scheduleNextProcess() {
    currentProcess = readyList.front();
    readyList.pop_front();
    currentProcess->schedule();
    workingContext = currentProcess->getContext();
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