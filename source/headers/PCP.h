//
// Created by novais 10/09/23.
//

#ifndef SO1_T1_PCP_H
#define SO1_T1_PCP_H

#include <vector>
#include <list>
#include "Process.h"
#include "Scheduler.h"

class PCP : public Scheduler {
public:
    explicit PCP(std::vector<Process *> processes) {
        this->processes = std::move(processes);
    }

    /**
     * @brief Método que executa o escalonador Prioridade com Preempção.
     *
     * O método executa o escalonador Prioridade com Preempção. O escalonador é preemptivo, ou seja, os processos
     * são executados até o final ou até que um processo com maior prioridade esteja na fila de execução de processos.
     * O escalonamento é feito de acordo com a prioridade de cada processo, ou seja, o processo com maior prioridade
     * é executado primeiro. Caso existam processos com a mesma prioridade, o escalonador executa os processos de acordo
     * com a ordem de chegada.
     *
     */
    void runScheduler() override;

private:
    std::list<Process *> readyList = std::list<Process *>();


    static bool comparePriority(Process *a, Process *b);

    /**
     * @brief Método que verifica se um processo com maior prioridade chegou na fila de execução de processos.
     *
     * O método verifica se um processo com maior prioridade chegou na fila de execução de processos. Caso exista um
     * processo com maior prioridade, o processo que está sendo executado é interrompido e o processo com maior
     * prioridade é executado.
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

#endif //SO1_T1_PCP_H
