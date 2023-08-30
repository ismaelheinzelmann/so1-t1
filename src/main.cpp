#include "read_file.h"
#include "classes/FCFS.cpp"
#include <vector>
#include "classes/Process.cpp"
int main() {
    File f;
    f.read_file();

    std::vector<components::Process> processes;
    for (unsigned long i = 0; i < f.get_processes().size(); i++) {
        processes.emplace_back(i, f.get_processes()[i]->getPriority(), f.get_processes()[i]->getCreationTime(), f.get_processes()[i]->getDuration());
    }

    FCFS fcfs(processes);
    fcfs.runScheduler();
    return 0;
}
