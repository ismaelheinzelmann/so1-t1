//
// Created by ismael on 30/08/23.
//

#ifndef PROCESS_H
#define PROCESS_H

#include "ProcessContext.h"

namespace components {

    enum PROCESS_STATE {
        NOT_CREATED,
        READY,
        RUNNING,
        FINALIZED
    };

    struct ProcessStats {
        int turnarroundTime;
        int waitingTime;
        int contextSwitches;
    };

    class Process {
    public:
        Process(int id, int priority, int startTime, int duration);

        int getId() const;

        int getPriority() const;

        int getStartTime() const;

        int getDuration() const;

        PROCESS_STATE getState() const;

        int getTurnarroundTime() const;

        int getContextSwitches() const;

        int getWaitingTime() const;

        void instantiate();

        void create();

        void schedule();

        void run();

        void preempt();

        void finalize(int time);

        bool running() const;

        ProcessStats getStats() const;

    private:
        int id;
        int priority;
        int startTime;
        int duration;
        int remainingTime;
        int priorityLevel{};
        PROCESS_STATE state;
        int turnarroundTime{};
        int contextSwitches{};
        int lastStop;
        ProcessContext context;
    };

} // namespace components
#endif //PROCESS_H
