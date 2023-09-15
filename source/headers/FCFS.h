//
// Created by ismael on 31/08/23.
//

#ifndef SO1_T1_FCFS_H
#define SO1_T1_FCFS_H

#include <vector>
#include <queue>
#include "Process.h"
#include "Scheduler.h"

class FCFS : public Scheduler {
public:
    explicit FCFS(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    void runScheduler() override;

private:
    std::queue<Process *> readyQueue = std::queue<Process *>();

    void initialize() override;

    void run() override ;

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats();
};

#endif //SO1_T1_FCFS_H
