//
// Created by ismael on 31/08/23.
//

#ifndef SO1_T1_FCFS_H
#define SO1_T1_FCFS_H

#include <vector>
#include <queue>
#include "Process.h"

class FCFS {
public:
    explicit FCFS(std::vector <Process> processes);

    void runScheduler();

private:
    std::vector <Process> processes;
    std::vector <Process::ProcessStats> processesStats;
    std::queue <Process> readyQueue = std::queue<Process>();
    ProcessContext workingContext = ProcessContext();
    int time = 0;

    void verifyProcessesToCreate();

    void printTimelineHeader();

    void printTimeline();

    void printProcessesStats();
};

#endif //SO1_T1_FCFS_H
