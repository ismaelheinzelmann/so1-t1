//
// Created by ismael on 29/08/23.
//
#include "ProcessContext.cpp"
#include "Process.h"
namespace components {

    Process::Process(int id, int priority, int startTime, int duration) {
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
    int Process::getId() const {
        return id;
    }

    int Process::getPriority() const {
        return priority;
    }

    int Process::getStartTime() const {
        return startTime;
    }

    int Process::getDuration() const {
        return duration;
    }

    int Process::getPriorityLevel() const {
        return priorityLevel;
    }

    PROCESS_STATE Process::getState() {
        return state;
    }

    int Process::getTurnarroundTime() const {
        return turnarroundTime;
    }

    int Process::getContextSwitches() const {
        return contextSwitches;
    }

    int Process::getWaitingTime() const {
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
        contextSwitches++;
    }

    void finalize(int time) {
        state = FINALIZED;
        turnarroundTime = time - startTime;
    }

    bool running() const {
        return remainingTime > 0;
    }

    ProcessStats getStats() const {
        ProcessStats stats;
        stats.turnarroundTime = turnarroundTime;
        stats.waitingTime = getWaitingTime();
        stats.contextSwitches = contextSwitches;
        return stats;
    }
}