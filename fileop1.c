#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
int main()
{
	// write(1,"Hello\n",6);
	int n,readFile, writeFile,count =0;
	char buff[100];
	// write(1, buff, n);
	readFile = open("readHere",O_RDONLY);
	writeFile = open("writeHere",O_WRONLY| O_CREAT);
	while((n=read(readFile,buff,1))!=0)
	{
		count++;
		if(count<3 || count>6)
		write(writeFile,buff,1);
			continue;
		else
			

	}
	printf("Copy completed\n");
}