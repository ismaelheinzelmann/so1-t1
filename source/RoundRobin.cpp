//
// Created by ismael on 12/09/23.
//

#include "RoundRobin.h"

RoundRobin::RoundRobin(std::vector<Process *> processes) {
    this->processes = processes;
}

void RoundRobin::initialize() {
    this->readyList = std::list<Process *>();
    this->readyList.insert(this->readyList.end(), this->processes.begin(), this->processes.end());
    this->readyList.sort(RoundRobin::comparePriority);
}

void RoundRobin::runScheduler() {
    this->printTimelineHeader();
    this->run();
    this->printProcessesStats();
}

void RoundRobin::run() {
    while (!this->readyList.empty()) {
        for (auto &process : this->readyList) {
            if (this->currentProcess == nullptr){
                this->currentProcess = process;
                this->workingContext = this->currentProcess->getContext();
                this->currentProcess->schedule();
                this->currentProcess->run();
                if (this->currentProcess->running()) {
                    continue;
                } else {

                }
            } else {
                currentProcess->setContext(this->workingContext);
                currentProcess->preempt();
                this->currentProcess = process;
                this->workingContext = this->currentProcess->getContext();
            }
        }
    }
}

bool RoundRobin::comparePriority(Process *a, Process *b) {
    return a->getPriority() < b->getPriority();
}

void RoundRobin::verifyProcessesToCreate() {
    for (auto &process : this->processes) {
        if (process->getArrivalTime() == this->currentTime) {
            this->readyList.push_back(process);
        }
    }
}

void RoundRobin::printTimelineHeader() {
    std::cout << "Round Robin" << std::endl;
    std::cout << "Quantum: " << this->quantum << std::endl;
    std::cout << "Time\t";
    for (auto &process : this->processes) {
        std::cout << "P" << process->getId() << "\t";
    }
    std::cout << std::endl;
}

void RoundRobin::printTimeline() {
    std::cout << this->currentTime << "\t";
    for (auto &process : this->processes) {
        if (process->getStartTime() <= this->currentTime && process->getEndTime() > this->currentTime) {
            std::cout << "X\t";
        } else {
            std::cout << "\t";
        }
    }
    std::cout << std::endl;
}

void RoundRobin::printProcessesStats() {
    std::cout << "Process\tTurnaround Time\tWaiting Time" << std::endl;
    for (auto &process : this->processes) {
        std::cout << "P" << process->getId() << "\t" << process->getTurnaroundTime() << "\t\t\t" << process->getWaitingTime() << std::endl;
    }
}

