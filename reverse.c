#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
	int blob,readFile, writeFile,c;
	char buff[100];

	readFile = open("endFile",O_CREAT|O_RDONLY);
	writeFile = open("copyFile",O_CREAT | O_WRONLY);
	c=lseek(readFile,0,SEEK_END);
	printf("val of c is %d\n",c);
	while(c>0)
	{
		read(readFile,buff,1);
		printf("%s\n", buff);
		write(writeFile,buff,1);
		 lseek(readFile, -2, SEEK_CUR); 
		c--;
	}
printf("DONE\n");
  close(readFile);  //close the files
  close(writeFile);
}