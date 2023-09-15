//
// Created by novais on 10/09/23.
//

#ifndef SO1_T1_SJF_H
#define SO1_T1_SJF_H

#include <list>
#include <vector>
#include "Process.h"
#include "Scheduler.h"

class SJF : public Scheduler {
public:
    explicit SJF(std::vector<Process *> processes);

    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();

    void initialize() override;

    void run() override ;

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats();
};

#endif //SO1_T1_SJF_H
