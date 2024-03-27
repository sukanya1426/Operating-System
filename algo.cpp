#include <bits/stdc++.h>
using namespace std;

vector<int> priority = {2, 1, 4, 2, 3};
vector<int> burstTimes = {2, 1, 8, 4, 5};

void First_come_first_serve()
{
    vector<int> completionTime(priority.size());
    vector<int> turnAroundTimes(priority.size());
    vector<int> waitingTimes(priority.size());
    float AvgTurnRoundTime;
    float AvgWaitingTime;
    int A,W=0;

    cout << "|";
    int currentTime = 0;
   for (int i = 0; i < priority.size(); i++) {
   //    while (currentTime < priority[i]) {
    //        cout << "-----|";
    //        currentTime++;
     //   }
        cout << "p" << i << "-----|";
        completionTime[i] = currentTime + burstTimes[i];
        turnAroundTimes[i]= completionTime[i];
        currentTime += burstTimes[i];
        
    }
    cout << "\n";

    for (int  i = 0; i < priority.size(); i++) {
          
       // turnAroundTimes[i] = turnAroundTimes[i]+burstTimes[j];
        waitingTimes[i] = turnAroundTimes[i] - burstTimes[i];
        
    }

    cout << "Process\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < priority.size(); i++) {
        cout << "p" << i << "\t" << turnAroundTimes[i] << "\t\t\t" << waitingTimes[i] << "\n";
        A=turnAroundTimes[i]+A;
        W=waitingTimes[i]+ W;
        
    }
    
    AvgTurnRoundTime = A/5;
    cout<< AvgTurnRoundTime <<endl;
    AvgWaitingTime = W/5;
    cout << AvgWaitingTime << endl;
    
    
}

void shortest_job_first()
{

    for(int i =0;i<priority.size();i++)
    {
        

}


int main() {
   
     First_come_first_serve();

    return 0;
}

