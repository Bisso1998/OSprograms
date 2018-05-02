#include<stdlib.h>
#include<stdio.h>
int main()
{
	int p1,p2;
	printf("[Parent process] %d \n",getpid() );
	p1=fork();
	if(p1==0)
	{
		printf("[Child] %d of [Parent] %d \n", getpid(),getppid());
		int p3;
		p3=fork();
		if(p3==0)
		{
		printf("[Child] %d of [Parent] %d \n", getpid(),getppid());
		}
		else
		{
			wait(NULL);
			int p4;
			p4=fork();
			if(p4==0)
			{
		printf("[Child] %d of [Parent] %d \n", getpid(),getppid());

			}
			else
			{
				wait(NULL);
			}
		}
	}
	else
	{
		p2=fork();
		if(p2==0)
		{
		printf("[Child] %d of [Parent] %d \n", getpid(),getppid());

		}
	}
}