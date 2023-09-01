//
// Created by ismael on 31/08/23.
//

#include "source/Process.h"
#include "source/ProcessContext.h"
#include <iostream>
#include "source/FCFS.h"

int main() {
    auto *p1 = new Process(1, 0, 5, 2);
    auto *p2 = new Process(2, 0, 2, 3);
    auto *p3 = new Process(3, 1, 4, 1);
    auto *p4 = new Process(4, 3, 3, 4);


    FCFS scheduler = FCFS(std::vector<Process *>{p1, p2, p3, p4});
    scheduler.runScheduler();
}