#include "RoundRobin.h"
#include "Process.h"

RoundRobin::RoundRobin(std::vector<Process *> processes) {
    this->processes = processes;
}

void RoundRobin::initialize() {
    if (!readyList.empty()) {
        currentProcess = readyList.front();
        readyList.pop_front();
        workingContext = currentProcess->getContext();
        currentProcess->schedule();
        currentProcess->run();
        state = RUNNING;
    }
}

void RoundRobin::run() {
    if (processes.size() == processesStats.size()){
        state = FINISHED;
        return;
    }
    

}

void RoundRobin::verifyProcessesToCreate() {
    for (auto &process : this->processes) {
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
