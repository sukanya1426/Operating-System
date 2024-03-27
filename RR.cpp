#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
  string name;
  int burstTime;
  int priority;
};

int main() {

  int quantum; 
  cout << "Enter quantum -> ";
  cin >> quantum;

  
  vector<Process> processes = {
      {"P1", 2, 2}, 
      {"P2", 1, 1},
      {"P3", 8, 4},
      {"P4", 4, 2},
      {"P5", 5, 3},
  };

  vector<int> completionTime; 
  int currTime = 0; 

  cout << "|";
  for (auto p : processes) {
    printf("---%s---|", p.name.c_str());
  }
  cout << endl;
  printf("%-9d", 0);


  while (!processes.empty()) {
    for (int i = 0; i < processes.size() && !processes.empty(); i++) {
      
      if (processes[i].burstTime <= quantum) {
        currTime += processes[i].burstTime;
        completionTime.push_back(currTime);
        printf("%-9d", currTime);
        processes.erase(processes.begin() + i); 
      } else {
        
        currTime += quantum;
        processes[i].burstTime -= quantum; 
        printf("%-9d", currTime);
      }
    }
  }

  cout << endl << endl;

  printf("%10s %10s %10s\n", "Process ID", "Turn Time", "Wait Time");

  vector<int> turnAroundTime, waitingTime;
  int totalTurnAroundTime = 0, totalWaitingTime = 0;
  for (int i = 0; i < completionTime.size(); i++) {
    turnAroundTime.push_back(completionTime[i] - processes[i].burstTime);
    waitingTime.push_back(turnAroundTime[i] - processes[i].burstTime);
    totalTurnAroundTime += turnAroundTime[i];
    totalWaitingTime += waitingTime[i];
  }

  for (int i = 0; i < completionTime.size(); i++) {
    printf("P%-9d %10d %10d\n", i + 1, turnAroundTime[i], waitingTime[i]);
  }

  double avgTurnAroundTime = (double)totalTurnAroundTime / completionTime.size();
  double avgWaitingTime = (double)totalWaitingTime / completionTime.size();

  printf("Average Turn Around Time: %.2lf\n", avgTurnAroundTime);
  printf("Average Waiting Time: %.2lf\n", avgWaitingTime);

  return 0;
}
