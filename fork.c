#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
//what the child process looks like after fork is called
void main()
{
    int a, b;
	printf("[Current Process] %d\n", getpid() );
	if(fork()==0)
	{
		printf("[child] %d [parent] %d \n",getpid(),getppid() );
		if(fork()==0)
		{
		printf("[child] %d [parent] %d \n",getpid(),getppid() );
		if(fork()==0)
		{
		printf("[child] %d [parent] %d \n",getpid(),getppid() );
		if (fork()==0)
		{
			/* code */
		printf("[child] %d [parent] %d \n",getpid(),getppid() );
			
		}
		}
		}
	}    
}

// what the parent process looks like after fork is called

