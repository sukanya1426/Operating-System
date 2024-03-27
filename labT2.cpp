#include <iostream>
#include <vector>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;


void multiplyRow(const vector<vector<int>>& A, const vector<vector<int>>& B, int row, vector<vector<int>>& result) {
    for (int j = 0; j < B[0].size(); ++j) {
        int sum = 0;
        for (int k = 0; k < A[0].size(); ++k) {
            sum += A[row][k] * B[k][j];
        }
        result[row][j] = sum;
    }
}

int main() {
    int m, n, p;
    cout << "Enter the number of rows and columns of matrix A: ";
    cin >> m >> n;
    cout << "Enter the number of columns of matrix B: ";
    cin >> p;

    vector<vector<int>> A(m, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(p));
    vector<vector<int>> result(m, vector<int>(p));

    cout << "elements of matrix A: ";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "elements of matrix B: ";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> B[i][j];
        }
    }

   
    for (int i = 0; i < m; ++i) {
        int pid = fork();

        if (pid < 0) {
            cerr << "Fork failed";
            return 1;
        } else if (pid == 0) {
            
            multiplyRow(A, B, i, result);
            cout << "Child process with PID " << getpid() << "finished multiplication of row " << i << endl;
            exit(0);
        }
    }

   

  
    cout << "Resultant matrix after multiplication:\n";
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}


