#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
int main()
{
	int f[2],p;
	pipe(f);
	char buff[100];
	p=fork();
	if(p==0)
	{
		close(f[0]);
		write(f[1],"Hello\n",6);
		wait();
	}
	else
	{
		close(f[1]);
		read(f[0],buff,100);
		printf("%s\n", buff);
	}
}