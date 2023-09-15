//
// Created by ismael on 31/08/23.
//

#include "Process.h"
#include <iostream>
using namespace std;

Process::Process(int id, int startTime, int duration, int priority) {
    this->id = id;
    this->priority = priority;
    this->startTime = startTime;
    this->duration = duration;
    remainingTime = duration;
    this->state = CREATED;
    lastStop = startTime;

    context = ProcessContext();
}

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


Process::PROCESS_STATE Process::getState() const {
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


void Process::create() {
    state = READY;
}

void Process::schedule() {
    state = RUNNING;
}

void Process::run() {
    if (remainingTime > 0) {
        remainingTime--;
    } else {
        state = FINISHED;
    }
}

void Process::preempt() {
    state = READY;
}

void Process::finalize(int time) {
    turnarroundTime = time - startTime;
}

bool Process::isRunning() const {
    return state == PROCESS_STATE::RUNNING;
}

bool Process::isOver() const {
    return remainingTime == 0;
}

Process::ProcessStats Process::getStats() {
    stats.id = id;
    stats.turnarroundTime = turnarroundTime;
    stats.waitingTime = getWaitingTime();
    stats.contextSwitches = contextSwitches;
    return stats;
}

ProcessContext Process::getContext() {
    contextSwitches++;
    return context;
}

void Process::setContext(ProcessContext processContext) {
    contextSwitches++;
    context = processContext;
}
