#include "RoundRobin.h"
#include "Process.h"
#include <iostream>

RoundRobin::RoundRobin(std::vector<Process *> processes) {
    this->processes = processes;
}

void RoundRobin::initialize() {
    if (!readyList.empty()) {
        scheduleNextProcess();
        state = RUNNING;
    }
}

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

//Chegou em 0 ? Se sim, escalona o próximo processo, roda o processo atual e verifica se ele terminou
//Chegou no quantum ? Se sim, verifica se o processo terminou, se sim, escalona o próximo processo, se não, preempta o processo atual
void RoundRobin::run() {
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
    while (readyList.empty()) {
        verifyProcessesToCreate();
    }
    while (processes.size() != processesStats.size()) {
        scheduleNextProcess();
        for (int i = 0; i < quantum; i++) {
            verifyProcessesToCreate();
            currentProcess->run();
            printTimeline();
            time++;
            if (currentProcess->isOver()) {
                finalizeProcess(currentProcess);
                break;
            }
        }
        preemptCurrentProcess();
    }
    printProcessesStats();
}
