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
            remainingTime = duration;
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

        int getWaitingTime() {
            return turnarroundTime - duration;
        }

        // Process Methods
        // Conseguir, ao final do processo:
        // Turnaround time -> Tempo desde a criação até o terminar sua execução.
        // Tempo médio de espera -> Tempo que estava em seu estado pronto.
        // Trocas de contexto -> Quantas vezes foi necessário trocar o contexto do processo. (Primeira execução ocorre uma troca)

        void instantiate() {
            state = NOT_CREATED;
        }

        void create() {
            state = READY;
        }

        void schedule() {
            state = RUNNING;
            contextSwitches++;
        }

        void run() {
            remainingTime--;
        }

        void preempt() {
            state = READY;
        }

        void finalize(int time) {
            state = FINALIZED;
            turnarroundTime = time - startTime;
        }

        bool running() {
            return remainingTime > 0;
        }

        ProcessStats getStats() {
            ProcessStats stats;
            stats.turnarroundTime = turnarroundTime;
            stats.waitingTime = getWaitingTime();
            stats.contextSwitches = contextSwitches;
            return stats;
        }


    private:
        int id;
        int priority;
        int startTime;
        int duration;
        int remainingTime;
        int priorityLevel;
        PROCESS_STATE state;

        int turnarroundTime;
        int contextSwitches;
        int lastStop;

        ProcessContext context;
    };
}