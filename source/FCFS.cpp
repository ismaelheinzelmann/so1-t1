//
// Created by ismael on 31/08/23.
//

#include "FCFS.h"
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Process.h"
#include "ProcessContext.h"
#include "Register.h"

void FCFS::runScheduler() {
    printTimelineHeader();
    Process *currentProcess = nullptr;
    while (true) {
        verifyProcessesToCreate();
        if (currentProcess != nullptr) {
            currentProcess->run();
            if (!currentProcess->running()) {
                currentProcess->finalize(time);
                processesStats.push_back(currentProcess->getStats());
                currentProcess = nullptr;
            }
        } else {
            if (!readyQueue.empty()) {
                currentProcess = readyQueue.front();
                workingContext = currentProcess->getContext();
                currentProcess->schedule();
                currentProcess->run();
                readyQueue.pop();
            } else {
                break;
            }
        }
        printTimeline();
        FCFS::time++;
    }
    printProcessesStats();
}

void FCFS::verifyProcessesToCreate() {
    for (auto it = processes.begin(); it != processes.end();) {
        if ((*it)->getStartTime() == time) {
            readyQueue.push(*it);
            it = processes.erase(it);
        } else {
            ++it;
        }
    }
}

void FCFS::printTimelineHeader() {
    std::cout << "tempo\t";
    for (const auto &process: processes) {
        std::cout << "P" << process->getId() << "\t";
    }
    std::cout << std::endl;
}

void FCFS::printTimeline() {
    std::cout << time << "-" << time + 1 << "\t";
    for (const auto &process: processes) {
        if (process->getState() == Process::PROCESS_STATE::RUNNING) {
            std::cout << "##\t";
        } else if (process->getState() == Process::PROCESS_STATE::READY) {
            std::cout << "--\t";
        } else {
            std::cout << "XD\t";
        }
    }
    std::cout << std::endl;
}

FCFS::FCFS(std::vector<Process*> processes) {
    this->processes = processes;
}


void FCFS::printProcessesStats() {
    std::cout << "Processo\tTurnaround\tWaiting\tContext Switches" << std::endl;
    for (const auto &processStats: processesStats) {
        std::cout << processStats.id << "\t\t\t" << processStats.turnarroundTime << "\t\t\t" << processStats.waitingTime
                  << "\t\t\t"
                  << processStats.contextSwitches << std::endl;
    }
}