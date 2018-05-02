#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *calcFib( val)
{
    int count=0;
    int first=0,second=1,third=0;
    while(count<val)
    {
        third = first +second;
        printf("%d \n",third );
        first = second;
        second = third;
        count++;

    }   
    wait(1); 
    printf("Calculating fibonacci of  %d \n",val);
    return NULL;
}
  
  void *calcFac( val)
{
    int fac=1;
    while(val>0)
    {
        fac=fac*val;
        val--;
    }
    wait(1);
    printf("Calculating factoral %d  is %d  \n",val,fac);
    return NULL;
}
  
int main()
{
    pthread_t tid1,tid2;
    int i=10;
    printf("Before Thread \n");
    pthread_create(&tid1, NULL, calcFib, i);
    pthread_join(tid1, NULL);
    pthread_create(&tid2, NULL, calcFac, i);
    pthread_join(tid2, NULL);
    printf("After Thread\n");
    exit(0);
}
