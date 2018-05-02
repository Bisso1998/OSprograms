#include<stdio.h>
int main()
{
	printf("%d\n",getpid() );
	if(fork()==0)
	{
		printf("[son] %d [parent] %d \n", getpid(),getppid());
		if (fork()==0)
		{
			/* code */
		printf("[son] %d [parent] %d \n", getpid(),getppid());
		
		if (fork()==0)
		{
			/* code */
		printf("[son] %d [parent] %d \n", getpid(),getppid());
			
		if (fork()==0)
		{
			/* code */
		printf("[son] %d [parent] %d \n", getpid(),getppid());
			
		}

		}

		// fork();


		}
	}
}