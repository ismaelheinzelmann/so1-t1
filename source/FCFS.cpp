//
// Created by ismael on 31/08/23.
//

#include "FCFS.h"
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Process.h"
#include "ProcessContext.h"
#include "Register.h"

void FCFS::runScheduler() {
    printTimelineHeader();

    bool running = true;
    while (running) {
        verifyProcessesToCreate();
        switch (state) {
            case INITIALIZED:
                initialize();
                break;
            case RUNNING:
                run();
                break;
            case FINISHED:
                running = false;
                break;
        }
        printTimeline();
        time++;
    }
    printProcessesStats();
}

void FCFS::verifyProcessesToCreate() {
    for (const auto &process: processes) {
        if (process->getStartTime() == time) {
            process->create();
            readyQueue.push(process);
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

// https://stackoverflow.com/questions/25918057/how-to-set-a-fixed-width-with-cout
void FCFS::printTimeline() {
    std::cout << std::setw(2) << time << "-" << std::setw(2) << time + 1 << "\t";
    for (const auto &process: processes) {
        if (process->getState() == Process::PROCESS_STATE::RUNNING) {
            std::cout << "##\t";
        } else if (process->getState() == Process::PROCESS_STATE::READY) {
            std::cout << "--\t";
        } else {
            std::cout << "  \t";
        }
    }
    std::cout << std::endl;
}

FCFS::FCFS(std::vector<Process *> processes) {
    this->processes = processes;
}

void FCFS::printProcessesStats() {
    std::cout << "Processo\tTurnaround\tWaiting\t\tTroca de Contexto" << std::endl;
    for (const auto &processStats: processesStats) {
        std::cout << processStats.id << "\t\t\t" << processStats.turnarroundTime << "\t\t\t" << processStats.waitingTime
                  << "\t\t\t"
                  << processStats.contextSwitches << std::endl;
    }
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