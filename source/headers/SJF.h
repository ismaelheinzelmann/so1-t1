//
// Created by novais on 10/09/23.
//

#ifndef SO1_T1_SJF_H
#define SO1_T1_SJF_H

#include <list>
#include <utility>
#include <vector>
#include "Process.h"
#include "Scheduler.h"

class SJF : public Scheduler {
public:
    explicit SJF(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    /**
     * @brief Método que executa o escalonador Shortest Job First.
     *
     * O método executa o escalonador Shortest Job First. O escalonador não é preemptivo, ou seja, os processos
     * são executados até serem finalizados.
     * O escalonamento é feito de acordo com tempo de execução de cada processo, ou seja, o processo com menor tempo de execução
     * é executado primeiro. Caso existam processos com o mesmo tempo de execução, o escalonador executa os processos de acordo
     * com a ordem de chegada.
     *
     */
    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();

    void verifyProcessesToCreate() override;

    void printTimelineHeader() override;

    void printTimeline() override;

    void printProcessesStats() override;
};

#endif //SO1_T1_SJF_H
