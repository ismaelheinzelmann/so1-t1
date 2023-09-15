//
// Created by novais 10/09/23.
//

#ifndef SO1_T1_PSP_H
#define SO1_T1_PSP_H

#include <vector>
#include <list>
#include "Process.h"
#include "Scheduler.h"

class PSP : public Scheduler {
public:
    explicit PSP(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();

    void initialize() override;

    bool static comparePriority(Process* a, Process* b);

    void run() override ;

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats();
};

#endif //SO1_T1_PSP_H