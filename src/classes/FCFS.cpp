//
// Created by ismael-dev on 30/08/23.
//
#include "Process.h"
#include "FCFS.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace schedulers {

    void FCFS::scheduleProcess(components::Process process) {
        processes.push_back(process);
    }

    void FCFS::verifyProcessesToCreate() {
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->getStartTime() == time) {
                it->create();
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
            std::cout << "P" << process.getId() << "\t";
        }
        std::cout << std::endl;
    }

    void FCFS::printTimeline() {
        std::cout << time << "-" << time + 1 << "\t";
        for (const auto &process: processes) {
            if (process.getState() == components::PROCESS_STATE::RUNNING) {
                std::cout << "##\t";
            } else if (process.getState() == components::PROCESS_STATE::READY) {
                std::cout << "--\t";
            } else {
                std::cout << "  \t";
            }
        }
        std::cout << std::endl;
    }

    void printProcessesStats() {
        ;
    }

    FCFS::FCFS(std::vector<components::Process> processes) {
        this->processes = processes;
        // Sort processes by its start time
        std::sort(this->processes.begin(), this->processes.end(), [](components::Process a, components::Process b) {
            return a.getId() < b.getId();
        });
    }

    void FCFS::runScheduler() {
        // FCFS não precisa de prioridade ou preemptividade
        // Processo roda até finalizar e o próximo da fila é executado
        printTimelineHeader();
        components::Process *currentProcess = nullptr;
        while (1) {
            verifyProcessesToCreate();
            if (currentProcess != nullptr) {
                if (currentProcess->running()) {
                    currentProcess->run();
                } else {
                    currentProcess->finalize(time);
                    processesStats.push_back(currentProcess->getStats());
                    currentProcess = nullptr;
                }
            } else {
                if (!readyQueue.empty()) {
                    currentProcess = &readyQueue.front();
                    currentProcess->run();
                    readyQueue.pop();
                } else {
                    break;
                }
            }
            printTimeline();
            time++;
        }
        printProcessesStats();
    }

};