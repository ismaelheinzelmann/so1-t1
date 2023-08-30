//
// Created by ismael on 30/08/23.
//

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Process.h"

class Scheduler {
public:
    virtual void scheduleProcess(components::Process process) = 0;
    virtual void runScheduler() = 0;
    virtual void verifyProcessesToCreate() = 0;
    virtual void printTimelineHeader() = 0;
    virtual void printTimeline() = 0;
    virtual void printProcessesStats() = 0;
};
#endif //SCHEDULER_H
