#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>
#define MAX_SIZE 10

void multiplyRow(int m, int n, int p, int A[m][n],  int B[n][p], int row, int result[m][p]) {
    for (int j = 0; j < p; ++j) {
        int sum = 0;
        for (int k = 0; k < n; ++k) {
        sum += A[row][k] * B[k][j];
        }
        result[row][j] = sum;
        //printf ("%d ",sum);
    }
}

int main() {
    int m, n, p;
    printf("number of rows and columns of matrix A:");
    scanf("%d %d", &m, &n);
    printf("number of columns of matrix B:");
    scanf("%d", &p);
    int A[m][n], B[n][p];
    int result[m][p];

    
   

    printf("elements of matrix A:\n");
    for (int i = 0; i < m; ++i) {
     for (int j = 0; j < n; ++j) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("elements of matrix B:\n");
    for (int i = 0; i < n; ++i) {
     for (int j = 0; j < p; ++j) {
            scanf("%d", &B[i][j]);
        }
    }
    for (int i = 0; i < m; ++i) {
        int pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            multiplyRow(m,n,p,A, B, i, result);
            for(int j=0;j<n;j++){
                  printf("%d ",result[i][j]);
             
            
        } printf("\n");
        exit(0);
       
}  wait(NULL);

    }
 

    

  
   

    return 0;
}

