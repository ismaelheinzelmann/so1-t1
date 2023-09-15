//
// Created by ismael on 12/09/23.
//


#ifndef SO1_T1_ROUNDROBIN_H
#define SO1_T1_ROUNDROBIN_H
#define QUANTUM 2
#include "Scheduler.h"
#include "Process.h"
#include <vector>
#include <list>

class RoundRobin : public Scheduler {
public:
    explicit RoundRobin(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();
    int quantum = QUANTUM;

    void preemptCurrentProcess();

    void scheduleProcess(Process *process);

    void finalizeProcess(Process *process);

    void scheduleNextProcess();

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats() override;
};

#endif //SO1_T1_ROUNDROBIN_H
