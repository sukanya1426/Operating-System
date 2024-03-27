#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int max;
int min;
float avg;
int size=5;

void *running1(void *varg) 
{
    size_t i;
    int *arr = (int *) varg;
    min = arr[0];
    for (i = 1; i < size; ++i) {
        if (min > arr[i]) {
            min = arr[i];
        }
    }

}

void *running2(void *varg) 
{
    size_t i;
    int *arr = (int *) varg;
    max = arr[0];
    for (i = 1; i < size; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }        
}

void *running3(void *varg){

   size_t i;
   int *arr = (int *)varg;
   int sum=0;
   for(i = 1;i< size ;i++){
    sum+=arr[i];
   }

   avg=sum/size;




}



 

int main()
{   
    int num;
   
    int list[5]={1,2,3,4,5};

    

    pthread_t tid,tid1,tid2;
    printf("Before Threads\n");
    pthread_create(&tid, NULL, running1, (void*) &list); 
    pthread_create(&tid1, NULL, running2, (void*) &list);
    pthread_create(&tid2, NULL, running3, (void*) &list);
  
    pthread_join(tid, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    printf("\nmin is %d \n ", min);
    printf("\nmax is %d \n ", max);
    printf("\navrg is %.2f \n ", avg);
}