//
// Created by ismael on 04/09/23.
//

#ifndef SO1_T1_SCHEDULER_H
#define SO1_T1_SCHEDULER_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "Process.h"
#include "ProcessContext.h"

class Scheduler {

protected:

    virtual void verifyProcessesToCreate() = 0;

    virtual void printTimelineHeader() {
        std::cout << "tempo\t";
        for (const auto &process: processes) {
            std::cout << "P" << process->getId() << "\t";
        }
        std::cout << std::endl;
    }

    virtual void printTimeline() {
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

    virtual void initialize() = 0;

    virtual void run() = 0;

    virtual void printProcessesStats() {
        std::cout << "Processo\tTurnaround\tWaiting\t\tTroca de Contexto" << std::endl;
        for (const auto &processStats: processesStats) {
            std::cout << processStats.id << "\t\t\t" << processStats.turnarroundTime << "\t\t\t"
                      << processStats.waitingTime
                      << "\t\t\t"
                      << processStats.contextSwitches << std::endl;
        }
    }


    enum SCHEDULER_STATES {
        INITIALIZED,
        RUNNING,
        FINISHED
    };
    SCHEDULER_STATES state = INITIALIZED;
    int time = 0;
    std::vector<Process *> processes;
    Process *currentProcess = nullptr;
    ProcessContext workingContext = ProcessContext();
    std::vector<Process::ProcessStats> processesStats;

public:
    virtual void runScheduler() {
        printTimelineHeader();
        while (true) {
            verifyProcessesToCreate();
            switch (state) {
                case INITIALIZED:
                    initialize();
                    break;
                case RUNNING:
                    printTimeline();
                    run();
                    break;
                case FINISHED:
                    printProcessesStats();
                    return;
            }
            time++;
        }
    }
};

#endif //SO1_T1_SCHEDULER_H
