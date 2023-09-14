#include "RoundRobin.h"
#include "Process.h"

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
    currentProcess = nullptr;
}

void RoundRobin::scheduleProcess(Process *process) {
    if (currentProcess != nullptr) {
        preemptProcess(currentProcess);
    }
    currentProcess = process;
    workingContext = currentProcess->getContext();
    currentProcess->schedule();
    currentProcess->run();
}

void RoundRobin::finalizeProcess(Process *process) {
    process->finalize(time);
    processesStats.push_back(process->getStats());
}

void RoundRobin::scheduleNextProcess() {
    scheduleProcess(readyList.front());
    readyList.pop_front();
}

void RoundRobin::run() {
    if (processes.size() == processesStats.size()) {
        state = FINISHED;
        return;
    }
    currentQuantum++;
    if (currentQuantum == 0) {
        scheduleNextProcess();
        return;
    }
    if (currentQuantum == quantum) {
        if (!currentProcess->running()) {
            finalizeProcess(currentProcess);
        }
        scheduleNextProcess();
        currentQuantum = 0;
        return;
    }
    currentProcess->run();
    if (!currentProcess->running()) {
        currentQuantum = 0;
        finalizeProcess(currentProcess);
        scheduleNextProcess();
    }
}

void RoundRobin::verifyProcessesToCreate() {
    for (auto &process: this->processes) {
        if (process->getStartTime() == this->time) {
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
    Scheduler::runScheduler();
}
