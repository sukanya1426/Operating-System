#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    string name;
    int burstTime;
    int priority; 
};

bool compareTwoProcess(Process a, Process b) {
    return a.burstTime < b.burstTime; 
}

int main() {
   
    vector<Process> processes = {
        {"P1", 2, 2}, 
        {"P2", 1, 1},
        {"P3", 8, 4},
        {"P4", 4, 2},
        {"P5", 5, 3},
    };

    
    sort(processes.begin(), processes.end(), compareTwoProcess);

    vector<int> turn, wait; 
    int currTime = 0;

    cout << "|";
    for (auto p : processes) {
        printf("---%s---|", p.name.c_str());
    }
    cout << endl;

    printf("%-9d", 0);
    for (int i = 0; i < processes.size(); i++) {
        currTime += processes[i].burstTime;
        printf("%-9d", currTime);
        turn.push_back(currTime);
        wait.push_back(currTime - processes[i].burstTime);
    }

    cout << endl << endl;

    printf("%10s %10s %10s\n", "Process ID", "Turn Time", "Wait Time");
    for (int i = 0; i < turn.size(); i++) {
        printf("P%-9d %10d %10d\n", i + 1, turn[i], wait[i]);
    }

    int sumWait = 0, sumTurn = 0; 
    for (int t : turn) {
        sumTurn += t;
    }
    for (int w : wait) {
        sumWait += w;
    }

    printf("Average Turn Around Time: %.2lf\n", (double)sumTurn / processes.size());
    printf("Average Waiting Time: %.2lf\n", (double)sumWait / processes.size());

    return 0;
}
