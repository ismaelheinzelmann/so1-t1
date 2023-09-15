//
// Created by ismael on 31/08/23.
//

#ifndef SO1_T1_FCFS_H
#define SO1_T1_FCFS_H

#include <vector>
#include <queue>
#include "Process.h"
#include "Scheduler.h"

class FCFS : public Scheduler {
public:
    explicit FCFS(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    /**
     * @brief Implementa o algoritmo de escalonamento First Come First Served.
     *
     * O algoritmo FCFS é um algoritmo de escalonamento não preemptivo, ou seja, os processos são executados até o
     * final sem interrupções. O escalonamento é feito de acordo com a ordem de chegada dos processos, ou seja, o
     * primeiro processo a chegar é o primeiro a ser executado.
     *
     */
    void runScheduler() override;

private:
    std::queue<Process *> readyQueue = std::queue<Process *>();

    /**
     * @brief Verifica se existem processos para serem criados no tempo atual para serem colocados na fila de escalonamento.
     *
     * O método verifica se existem processos para serem criados no tempo atual para serem colocados na estrutura FIFO
     * de escalonamento. Caso existam, os processos são colocados na fila de escalonamento.
     *
     */
    void verifyProcessesToCreate() override;


    /**
     * @brief Imprime o cabeçalho da linha do tempo.
     *
     * O método imprime o cabeçalho da linha do tempo, que é composto pelos identificadores o de cada processo.
     *
     */
    void printTimelineHeader() override;

    /**
     * @brief Imprime a linha do tempo.
     *
     * O método imprime a linha do tempo, que é composta pelos tempos de execução de cada processo.
     *
     */
    void printTimeline() override;

    /**
     * @brief Imprime as estatísticas dos processos.
     *
     * O método imprime as estatísticas dos processos, que são o tempo de espera, o tempo de retorno e as trocas de
     * contexto de cada processo.
     *
     */
    void printProcessesStats() override;
};

#endif //SO1_T1_FCFS_H
