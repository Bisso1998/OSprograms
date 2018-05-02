#include <stdlib.h>
#include <pthread.h>

void *add()
{
	int a =10,b=5;
	printf("Val of a and b %d and %d\n",a,b);
	wait(1);
	return a+b;
	
}
void multiply2()
{
	
	int a=10,b=2;
	printf("Fun is %d\n",a*b );
	printf("Val of a and b %d and %d \n",a,b);
wait(1);
	return a*b;
	
}

int main()
{
	void *status1,*status2;
	pthread_t p1,p2;

	pthread_create(&p1,NULL,add,NULL);
	pthread_join(p1,&status1);
	printf("Sum = %d\n",status1 );


	pthread_create(&p2,NULL,multiply2,NULL);
	pthread_join(p2,&status2);
	printf("Product = %d\n",status2 );


}