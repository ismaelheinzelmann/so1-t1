//
// Created by ismael on 31/08/23.
//

#include "source/Process.h"
#include "source/ProcessContext.h"
#include <iostream>
#include "source/FCFS.h"

int main() {
    FCFS scheduler = FCFS(std::vector<Process>{
            Process(1, 0, 5, 2),
            Process(2, 0, 2, 3),
            Process(3, 1, 4, 1),
            Process(4, 3, 3, 4)
    });
    scheduler.runScheduler();
}