//
// Created by ismael on 29/08/23.
//
#include "ProcessContext.cpp"

namespace components {
    enum PROCESS_STATE {
        NOT_CREATED,
        READY,
        RUNNING,
        FINALIZED
    };

    class Process {
    public:
        Process(int id, int priority, int startTime, int duration) {
            this->id = id;
            this->priority = priority;
            this->startTime = startTime;
            this->duration = duration;
            this->state = NOT_CREATED;
            lastStop = startTime;

            context = ProcessContext();
        }

        // Getters
        int getId() {
            return id;
        }

        int getPriority() {
            return priority;
        }

        int getStartTime() {
            return startTime;
        }

        int getDuration() {
            return duration;
        }

        int getPriorityLevel() {
            return priorityLevel;
        }

        PROCESS_STATE getState() {
            return state;
        }

        int getTurnarroundTime() {
            return turnarroundTime;
        }

        int getContextSwitches() {
            return contextSwitches;
        }

        // Process Methods

        void create() {
            state = NOT_CREATED;
        }

        void schedule() {
            state = READY;
        }

        void run() {
            state = RUNNING;
        }

        void preempt(int time) {
            state = READY;
            lastStop = time;
        }

        void finalize() {
            state = FINALIZED;
        }

        bool isRunning() {
            return duration > 0;
        }


    private:
        int id;
        int priority;
        int startTime;
        int duration;
        int priorityLevel;
        PROCESS_STATE state;

        int turnarroundTime;
        int contextSwitches;
        int lastStop;

        ProcessContext context;
    };
}