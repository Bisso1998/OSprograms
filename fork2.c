#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("[Current] %d\n",getpid() );
	if(fork()==0)
	{
		printf("[child] %d P1 of [parent] %d \n",getpid() , getppid());
	}
	else 
	{
		printf("[parent] id is %d \n",getpid() );
		if(fork()==0)
		{
			printf("[child] P2 id: %d of [Parent] %d \n",getpid(),getppid() );
			// if(fork==0)
			// {
			// 	printf("[Child] %d P3 of [Parent] %d \n",getpid(),getppid() );
			// }
			// else
			// {
			// 	sleep(1);
			// 	if(fork()==0)
			// 	{
			// 		printf("[Child] %d P4 of [Parent] %d \n",getpid(),getppid() );
			// 	}
			// 	else
			// 	{
			// 		sleep(1);
			// 	}
			}
		}

	}
}