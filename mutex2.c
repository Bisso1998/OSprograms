#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

int shared =1;
pthread_mutex_t  l;
void *fun1()
{
	pthread_mutex_lock(&l);
	int x;
	x=shared;
	x++;
	sleep(1);
	shared=x;
	pthread_mutex_unlock(&l);
}
void *fun2()
{
	pthread_mutex_lock(&l);
	int x;
	x=shared;
	x--;
	sleep(1);
	shared=x;
	pthread_mutex_unlock(&l);
}
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,fun1,NULL);
	pthread_join(t1,NULL);
	pthread_create(&t2,NULL,fun2,NULL);
	pthread_join(t2,NULL);
	printf("Value of shared %d\n", shared);

}