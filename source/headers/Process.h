//
// Created by ismael on 31/08/23.
//

#ifndef SO1_T1_PROCESS_H
#define SO1_T1_PROCESS_H

#include "ProcessContext.h"

class Process {
public:

    /// Enum com os estados possíveis de um processo
    enum PROCESS_STATE {
        CREATED,
        READY,
        RUNNING,
        FINISHED
    };

    /// Struct com as estatísticas de um processo, como tempo de retorno, tempo de espera e número de trocas de contexto
    typedef struct ProcessStats {
        int id;
        int turnarroundTime;
        int waitingTime;
        int contextSwitches;
    } ProcessStats;

    Process(int id, int startTime, int duration, int priority);

    int getId() const;

    int getPriority() const;

    int getStartTime() const;

    int getDuration() const;

    PROCESS_STATE getState() const;

    int getTurnarroundTime() const;

    int getContextSwitches() const;

    int getWaitingTime() const;

    ProcessContext getContext();

    void setContext(ProcessContext processContext);

    void create();

    void schedule();

    void run();

    void preempt();

    void finalize(int time);

    bool isRunning() const;

    ProcessStats getStats();

    bool isOver() const;

private:
    int id;
    int priority;
    int startTime;
    int duration;
    int remainingTime;
    int turnarroundTime;
    PROCESS_STATE state;
    ProcessContext context;
    ProcessStats stats;
    int contextSwitches = 0;
};


#endif //SO1_T1_PROCESS_H
