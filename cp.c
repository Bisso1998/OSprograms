#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
	int n,m,x,count =0;
	char buffer[100];
	n=open("new_file",O_RDONLY);
	printf("value of n is: %d \n", n);
	m=open("new_file1",O_CREAT|O_WRONLY | O_APPEND);
	printf("value of m is: %d \n", m);
	
	while((x=read(n,buffer,1))!=0)
	{
		printf("Count is: %d and x is: %d\n",count,x );
		count++;
		if(count>=10&&count<=25)
		{
		write(m,buffer,x);
		}
	
	}
	printf("copy completed");
}