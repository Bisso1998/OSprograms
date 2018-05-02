#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(int argc, char const *argv[])
{
	/* code */
	int p1,p2;
	printf("I am a  Parent and my id is %d\n\n", getpid());
	p1 = fork();
	if(p1 == 0)
	{
		//Child
		printf("I am a process1 having id %d and my Parent is %d\n", getpid(),getppid());
		int p_3;
		p_3 = fork();
		if(p_3 == 0)
		{
			printf("I am a process3 having id %d and my Parent is %d\n", getpid(),getppid());
		}else
		{
			wait(NULL);
			if(fork() == 0)
			{
				printf("I am a process4 having id %d and my Parent is %d\n", getpid(),getppid());
			}else{
				wait(NULL);
			}
		}
	}
	else{
		wait(NULL);
		//Parent
		p2 = fork();
		if(p2 == 0){
			printf("I am a process2 having id %d and my Parent is %d\n", getpid(),getppid());
		}
	}
	return 0;
}