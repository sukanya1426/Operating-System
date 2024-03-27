#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int sum_even = 0;
    int sum_odd = 0;

    int pid = fork();

    if (pid < 0) {
        cerr << "Fork failed";
        return 1;
    } else if (pid == 0) {
        
        for (int i = 1; i <= n; i += 2) {
            sum_odd += i;
        }
        cout << "Sum of odd numbers from 1 to " << n << " in child process: " << sum_odd << endl;
    } else {
        
       
        for (int i = 2; i <= n; i += 2) {
            sum_even += i;
        }
        cout << "Sum of even numbers from 2 to " << n << " in parent process: " << sum_even << endl;
    }

    return 0;
}

