#include <bits/stdc++.h>
using namespace std;

int main() {

  vector<int> burstTime = {2,1,8,4,5};
  vector<int> priority ={2,1,4,2,3}; 
  vector<int> res;
  res.push_back(0);

  for (int i = 0; i < burstTime.size(); i++) {
    res.push_back(burstTime[i]);
  }

  vector<int> turn, wait;
  int currTime = 0;
  for (int i = 1; i <= burstTime.size(); i++) {
    currTime += res[i];
    printf("%-9d", currTime);
    turn.push_back(currTime);
    wait.push_back(currTime - res[i]);
  }

  cout << endl << endl;

  printf("%10s %10s %10s\n", "Process ID", "Turn Time", "Wait Time");
  for (int i = 0; i < turn.size(); i++) {
    printf("P%-9d %10d %10d\n", i + 1, turn[i], wait[i]);
  }


  int totalTurnaroundTime = 0, totalWaitingTime = 0;
  for (int i = 0; i < turn.size(); i++) {
    totalTurnaroundTime += turn[i];
    totalWaitingTime += wait[i];
  }
  double averageTurnaroundTime = (double)totalTurnaroundTime / burstTime.size();
  double averageWaitingTime = (double)totalWaitingTime / burstTime.size();

  printf("Average Turn Around Time: %.2lf\n", averageTurnaroundTime);
  printf("Average Waiting Time: %.2lf\n", averageWaitingTime);
}
