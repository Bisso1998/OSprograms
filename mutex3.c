#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
// pthread_mutex_t l;
sem_t l;

int shared = 100;
void *fun1()
{
	// pthread_mutex_lock(&l);
	sem_wait(&l);
	int x =shared;
	x=x-100;
	sleep(1);
	shared=x;
	// pthread_mutex_unlock(&l);
	sem_post(&l);


}
void *fun2()
{
	// pthread_mutex_lock(&l);
	sem_wait(&l);

	int y =shared;
	y=y+100;
	sleep(1);

	shared=y;
	// pthread_mutex_unlock(&l);
	sem_post(&l);

	
}

int main()
{
	sem_init(&l,0,1);

	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t2,NULL);
	printf("Value of shared is %d\n", shared);
	
}