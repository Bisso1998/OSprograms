#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int counter=0;
pthread_t tid[2];
pthread_mutex_t lock;
void *myThreadFun(void *vargp)
{
    pthread_mutex_lock(&lock);
    int i;
 	int myid = (int *)vargp;
 	printf("%d",myid);
    counter++;
    printf("PREV Printing GeeksQuiz from Thread Counter is 0000-> %d \n ",counter);
    for(i=0; i<(0xFFFFFFFF);i++);
    printf("AFTER Printing GeeksQuiz from Thread Counter is 0000--> %d \n ",counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}
  
int main()
{
    printf("Before Thread\n");
    for (int i = 0; i < 2; ++i)
    {
    	/* code */
    	pthread_create(&(tid[i]), NULL, myThreadFun, NULL);
     pthread_join(tid[i], NULL);

    	
    }
     pthread_mutex_destroy(&lock);
    // pthread_join(tid[1], NULL);
    printf("After Thread\n");
    exit(0);
}
