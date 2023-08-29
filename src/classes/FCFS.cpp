//
// Created by ismael-dev on 30/08/23.
//
#include "Process.cpp"
#include "Scheduler.cpp"
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

class FCFS : public Scheduler {
    FCFS(std::vector<components::Process> processes) {
        this->processes = processes;
        // Sort processes by its start time
        std::sort(this->processes.begin(), this->processes.end(), [](components::Process a, components::Process b) {
            return a.getId() < b.getId();
        });
    }

    void scheduleProcess(components::Process process) {
        processes.push_back(process);
    }

    void runScheduler() {
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

    void verifyProcessesToCreate() {
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].getStartTime() == time) {
                processes[i].create();
                readyQueue.push(processes[i]);
                processes.erase(processes.begin() + i);
            }
        }
    }

    void printTimelineHeader() {
        std::cout << "tempo\t";
        for (int i = 0; i < processes.size(); i++) {
            std::cout << "P" << processes[i].getId() << "\t";
        }
        std::cout << std::endl;
    }

    void printTimeline() {
        std::cout << time << "-" << time + 1 << "\t";
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].getState() == components::PROCESS_STATE::RUNNING) {
                std::cout << "##\t";
            } else if (processes[i].getState() == components::PROCESS_STATE::READY) {
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


private:
    std::vector<components::Process> processes;
    std::vector<components::ProcessStats> processesStats;
    std::queue<components::Process> readyQueue = std::queue<components::Process>();
    int time = 0;
};