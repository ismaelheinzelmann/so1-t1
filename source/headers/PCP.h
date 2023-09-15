//
// Created by novais 10/09/23.
//

#ifndef SO1_T1_PCP_H
#define SO1_T1_PCP_H

#include <vector>
#include <list>
#include "Process.h"
#include "Scheduler.h"

class PCP : public Scheduler {
public:
    explicit PCP(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();

    static bool comparePriority(Process* a, Process* b);

    void initialize() override;

    void run() override ;

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats();
};

#endif //SO1_T1_PCP_H
