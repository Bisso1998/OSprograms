#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *add()
{
    int a=5,b=10;
    return a+b;        
}
  
void *prod1()
{
    int a=2,b=10;
    return a*b;        
}
  
int main()
{
    pthread_t tid1,tid2;
       void *status1,*status2;

    int i=10,sum,prod;
    printf("Before Thread \n");


    pthread_create(&tid1, NULL, add, NULL);
   pthread_join(tid1,  &status1);


    pthread_create(&tid2, NULL, prod1, NULL);
    prod = pthread_join(tid2,  &status2);

    printf("Sum is %d \n",status1);
    printf("Prod is %d \n",status2);
}
