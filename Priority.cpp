#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Process {
    string name;
    int burstTime;
    int priority;
};
struct Result{
    string name;
    int start;
    int end;
};

bool compareTwoProcess(Process a, Process b) {
     if (a.priority != b.priority) {
        return a.priority > b.priority;
    }
    return a.burstTime < b.burstTime;
}

int main() {

    vector<Process> processes = {
        {"P1", 4, 3},
        {"P2", 2, 1},
        {"P3", 5, 2},
        {"P4", 1, 4},
        {"P5", 6, 5},
    };

  
    sort(processes.begin(), processes.end(), compareTwoProcess);

    vector<Result> ans;
    int currTime = 0; 
    cout << "|";
    for (auto p : processes) {
        printf("---%s---|", p.name.c_str());
    }
    cout << endl;

    printf("%-9d", 0);

    for (auto &p : processes) {
        currTime += p.burstTime;
        Result res;
        res.name = p.name;
        res.start = currTime - p.burstTime;
        res.end = currTime;
        ans.push_back(res);
    }

    cout << endl << endl;

    printf("%10s %10s %10s\n", "Process ID", "Turn Time", "Wait Time");

    map<string, int> turn, wait; 
    for (auto a : ans) {
        turn[a.name] = a.end; 
    }

    for (auto &p : processes) {
        wait[p.name] = turn[p.name] - p.burstTime; 
    }

    map<string, int>::iterator it2 = turn.begin();
    map<string, int>::iterator it3 = wait.begin();

    int avgTurn = 0, avgWait = 0;

    while (it2 != turn.end()) {
        printf("%-10s %10d %10d\n", it2->first.c_str(), it2->second, it3->second);
        avgTurn += it2->second;
        avgWait += it3->second;
        ++it2;
        ++it3;
    }

    printf("Average Turn Around Time: %.2lf\n", avgTurn / (double)processes.size());
    printf("Average Waiting Time: %.2lf\n", avgWait / (double)processes.size());

    return 0;
}
