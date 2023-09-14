//
// Created by ismael on 12/09/23.
//


#ifndef SO1_T1_ROUNDROBIN_H
#define SO1_T1_ROUNDROBIN_H

#include "Scheduler.h"
#include "Process.h"
#include <vector>
#include <list>

class RoundRobin : public Scheduler {
public:
    explicit RoundRobin(std::vector<Process *> processes);

    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();
    int quantum = 2;
    int currentQuantum = 0;

    void initialize() override;

    void preemptProcess(Process *process);

    void scheduleProcess(Process *process);

    void finalizeProcess(Process *process);

    void scheduleNextProcess();

    void run() override;

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats() override;
};

#endif //SO1_T1_ROUNDROBIN_H
