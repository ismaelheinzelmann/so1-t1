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

    /**
      * @brief Verifica se existem processos para serem criados no tempo atual para serem colocados na lista de escalonamento.
      *
      * O método verifica se existem processos para serem criados no tempo atual para serem colocados na estrutura lista
      * de escalonamento. Caso existam, os processos são colocados na lista de escalonamento e ordenados de acordo com seu tempo de execução.
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

    /// @brief Escalona o próximo processo na fila de execução.
    void scheduleNextProcess();

    /// @brief Finaliza o processo atual e insere suas estatísticas na lista de estatísticas.
    void finalizeCurrentProcess();;
};

#endif //SO1_T1_SJF_H
