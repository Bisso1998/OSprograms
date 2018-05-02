#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

int shared =1;
// pthread_mutex_t l; 
sem_t s;
void *fun1()
{
	printf("I am in fun1\n");
	int x,a=10,b=20;
	// pthread_mutex_lock(&l);
sem_wait(&s);
	x=shared;
	x++;
	sleep(1);
	shared=x;
	 // pthread_mutex_unlock(&l);
	 sem_post(&s);
	return a+b;
}

void *fun2()
{
	printf("I am in fun2\n");

	int y,a=2,b=3;
	// pthread_mutex_lock(&l);
sem_wait(&s);


	y=shared;
	y--;
	sleep(1);
	shared=y;
	 // pthread_mutex_unlock(&l);
	 sem_post(&s);
	return a*b;

}
int main()
{
	// pthread_mutex_init(&l, NULL);
	sem_init(&s,0,1);
	void *status1,*status2;
	pthread_t thread1, thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1, &status1);
	pthread_join(thread2, &status2);
	printf("Shared value is %d \n",shared );
	printf("Status value is %d \n",status1 );
	printf("Status2 value is %d \n",status2 );
}
