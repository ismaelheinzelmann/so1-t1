#include "source/Process.h"
#include "read_file.h"
#include <iostream>
#include "source/RoundRobin.h"
#include "source/SJF.h"
#include "source/FCFS.h"
#include "source/PSP.h"
#include "source/PCP.h"

int main() {
    std::cout << "Bem vindo ao simulador de escalonamento de processos." << std::endl;
    std::cout << "Escolha o algoritmo a ser utizado da seguinte lista:" << std::endl;
    std::cout << "1 -> FCFS (First Come, First Served)\n"
                 "2 -> Shortest Job First\n"
                 "3 -> Por prioridade, sem preempção \n"
                 "4 -> Por prioridade, com preempção por prioridade \n"
                 "5 -> Round-Robin com quantum = 2s, sem prioridade\n" << std::endl;

    File f;
    f.read_file();
    std::vector<Process *> processes;

    int i = 0;
    for (auto &p: f.get_processes()) {
        auto *newProcess = new Process(i, p->getCreationTime(), p->getDuration(), p->getPriority());
        processes.push_back(newProcess);
        i++;
    }

    Scheduler *scheduler;
    bool quebra = true;
    do {
        std::cout << "Sua escolha: " << std::endl;
        char choice;
        std::cin >> choice;

        switch (choice) {
            case '1':
                scheduler = new FCFS(processes);
                scheduler->runScheduler();
                quebra = false;
                break;
            case '2':
                scheduler = new SJF(processes);
                scheduler->runScheduler();
                quebra = false;
                break;
            case '3':
                scheduler = new PSP(processes);
                scheduler->runScheduler();
                quebra = false;
                break;
            case '4':
                scheduler = new PCP(processes);
                scheduler->runScheduler();
                quebra = false;
                break;
            case '5':
                scheduler = new RoundRobin(processes);
                scheduler->runScheduler();
                quebra = false;
                break;
            default:
                std::cout << "Opção inválida, tente novamente." << std::endl;
                break;
        }
    } while (quebra);

    for (auto &process: processes) delete process;


}