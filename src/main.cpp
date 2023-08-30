//
// Created by ismael on 24/08/23.
//

#include <iostream>

void menu() {
    std::cout<<"Escolha o algoritmo a ser utizado da seguinte lista:"<<std::endl;
    std::cout<<"1 -> FCFS (First Come, First Served)\n"
               "2 -> Shortest Job First\n"
               "3 -> Por prioridade, sem preempção \n"
               "4 -> Por prioridade, com preempção por prioridade \n"
               "5 -> Round-Robin com quantum = 2s, sem prioridade"<<std::endl;
    
    bool quebra = true;
    do
    {
        std::cout<<"Sua escolha: "<<std::endl;
        char choice;
        std::cin >> choice;
        
        switch (choice)
        {
        case '1':
            std::cout<<"Numero 1"<<std::endl;
            quebra = false;
            break;
        case '2':
            quebra = false;
            break;
        case '3':
            quebra = false;
            break;
        case '4':
            quebra = false;
            break;
        case '5':
            quebra = false;
            break;
        default:
            std::cout<<"Escolha um item da lista."<<std::endl;
        }
    } while (quebra);
}


int main(){
    menu();
    return 0;
}