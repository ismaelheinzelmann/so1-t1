#ifndef SO1_T1_READ_FILE_H
#define SO1_T1_READ_FILE_H

#endif //SO1_T1_READ_FILE_H

#include <c++/11/iostream>
#include <c++/11/fstream>
#include <c++/11/string>
#include <c++/11/vector>

using namespace std;

class ProcessParams {
public:
    ProcessParams(int c, int d, int p) {
        creation_time = c;
        duration = d;
        priority = p;
    }

    friend ostream &operator<<(ostream &os, const ProcessParams &p) {
        os << "Creation time = " << p.creation_time << " duration = " << p.duration << " priority = " << p.priority
           << endl;
        return os;
    }

    int getDuration() const {
        return duration;
    }

    int getPriority() const {
        return priority;
    }
    
    int getCreationTime() const {
        return creation_time;
    }



private:
    int creation_time;
    int duration; //seconds
    int priority;
};

class File {

public:
    File() {
        myfile.open("entrada.txt");
        if (!myfile.is_open()) {
            cout << "Erro ao abrir o arquivo!\n";
        }
    }

    void read_file() {

        int a, b, c;

        if (!myfile.is_open()) {
            cout << "Arquivo não está aberto!" << endl;
        }

        while (myfile >> a >> b >> c) {
            auto *p = new ProcessParams(a, b, c);
            processes.push_back(p);
        }

        cout << "Quantidade de processos lidos do arquivo: " << processes.size() << endl;
    }

    void print_processes_params() {
        auto iter = processes.begin();

        for (; iter < processes.end(); iter++) {
            ProcessParams *p = *iter;
            cout << *p;
        }
    }

    vector<ProcessParams *> get_processes() {
        return processes;
    }

    ~File() {
        for (auto p: processes) {
            delete p;
        }
    }

private:
    ifstream myfile;
    vector<ProcessParams *> processes;
};

//int main() {
//    File f;
//    f.read_file();
//    f.print_processes_params();
//}
