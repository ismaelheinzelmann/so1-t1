//
// Created by ismael on 30/08/23.
//

#ifndef FCFS_H
#define FCFS_H

#include <vector>
#include <queue>
#include "Process.h"
#include "Scheduler.h"

namespace schedulers {
    class FCFS : public Scheduler {
    public:
        explicit FCFS(std::vector<components::Process> processes);
        void runScheduler() override;

    private:
        std::vector<components::Process> processes;
        std::vector<components::ProcessStats> processesStats;
        std::queue<components::Process> readyQueue = std::queue<components::Process>();
        int time = 0;

        void scheduleProcess(components::Process process) override;

        void verifyProcessesToCreate() override;

        void printTimelineHeader() override;

        void printTimeline() override;
    };

}
#endif //FCFS_H
