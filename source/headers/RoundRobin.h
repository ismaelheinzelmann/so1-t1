//
// Created by ismael on 12/09/23.
//


#ifndef SO1_T1_ROUNDROBIN_H
#define SO1_T1_ROUNDROBIN_H
#define QUANTUM 2
#include "Scheduler.h"
#include "Process.h"
#include <vector>
#include <list>

class RoundRobin : public Scheduler {
public:
    explicit RoundRobin(std::vector<Process *> processes){
        this->processes = std::move(processes);
    }

    /**
     * @brief Implementa o algoritmo de escalonamento Round Robin.
     *
     * O algoritmo Round Robin é um algoritmo de escalonamento preemptivo, ou seja, os processos são executados até o
     * final ou até que o quantum de tempo seja atingido. O escalonamento é feito de acordo com a ordem de chegada dos
     * processos, ou seja, o primeiro processo a chegar é o primeiro a ser executado.
     *
     */
    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();
    int quantum = QUANTUM;

    /// @brief Interrompe a execução do processo atual, colocando-o na fila de processos prontos para serem executados.
    void preemptCurrentProcess();

    /// @brief Coloca um processo para ser executado.
    /// @param process Processo a ser executado.
    void scheduleProcess(Process *process);

    /// @brief Finaliza a execução de um processo, inserindo suas estatísticas na lista de estatísticas.
    void finalizeProcess(Process *process);

    /// @brief Executa o próximo processo da fila de processos prontos para serem executados.
    void scheduleNextProcess();


    /// @brief Verifica se existem processos para serem criados no tempo atual para serem colocados na fila de escalonamento.
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

#endif //SO1_T1_ROUNDROBIN_H
