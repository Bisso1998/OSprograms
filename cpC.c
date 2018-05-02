#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int n,m,x,count=0;
	char buffer[100];
	n=open("new_file",O_RDONLY);
	printf("value of n is: %d \n", n);
	m=open("new_file1",O_CREAT|O_WRONLY,0777);
	printf("value of m is: %d \n", m);
	
	while((x=read(n,buffer,1))!=0)
	{
		count++;
		if(count>=3&&count<=5)
		{
				write(m,buffer,x);

		}
	// printf("value of x is: %d \n", x);
	}
	printf("copy completed");
}