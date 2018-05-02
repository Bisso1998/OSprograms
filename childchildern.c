#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{

	printf("[currentP]: %d \n",getpid() );
	if(fork()==0)
	{
		printf("[childP1] %d [parent] %d \n",getpid(),getppid() );
	}
	if(fork()==0)
	{
		printf("[childP2] %d [parent] %d \n",getpid(),getppid() );
	}
}