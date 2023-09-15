//
// Created by ismael on 31/08/23.
//

#include "../headers/SJF.h"

bool compareDuration(Process *a, Process *b) {
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

void SJF::runScheduler() {
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

void SJF::finalizeCurrentProcess() {
    currentProcess->finalize(time);
    processesStats.push_back(currentProcess->getStats());
}

void SJF::scheduleNextProcess() {
    currentProcess = readyList.front();
    readyList.pop_front();
    currentProcess->schedule();
    workingContext = currentProcess->getContext();
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
