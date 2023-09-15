//
// Created by novais 10/09/23.
//

#include "../headers/PCP.h"
#include <vector>
#include <iostream>
#include <iomanip>

bool PCP::comparePriority(Process* a, Process* b){
    return a->getPriority() > b->getPriority();
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
    ;
}

void PCP::runScheduler() {
    printTimelineHeader();
    verifyProcessesToCreate();
    while (processes.size() != processesStats.size()) {
        if (readyList.empty()) {
            printTimeline();
            time++;
            verifyProcessesToCreate();
            continue;
        }
        currentProcess = readyList.front();
        readyList.pop_front();
        currentProcess->schedule();
        workingContext = currentProcess->getContext();

        for (int i = 0; i < currentProcess->getDuration(); ++i) {
            if (currentProcess->getPriority() < readyList.front()->getPriority()){
                currentProcess->preempt();
                currentProcess->setContext(workingContext);
                readyList.push_back(currentProcess);
                readyList.sort(comparePriority);
                currentProcess = nullptr;
                break;
            }
            currentProcess->run();
            printTimeline();
            time++;
            verifyProcessesToCreate();
        }
        if (currentProcess->isOver()){
            currentProcess->finalize(time);
            processesStats.push_back(currentProcess->getStats());
        }
    }
    printProcessesStats();
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