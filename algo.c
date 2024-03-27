#include <bits/stdc++.h>
using namespace std;

int main() {
   
    vector<int> priority = {2, 1, 4, 2, 3};
    vector<int> burstTimes = {2, 1, 8, 4, 5};

    cout << "|";
    int currentTime = 0;
    for (size_t i = 0; i < priority.size(); i++) {
       
        while (currentTime < priority[i]) {
            cout << "-----|";
            currentTime++;
        }
        
       
        cout << "p" << i << "-----|";
        currentTime += burstTimes[i];
    }
    cout << "\n";

    return 0;
}

