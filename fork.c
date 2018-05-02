#include<stdio.h>
#include <sys/types.h>
#include<unistd.h>
//what the child process looks like after fork is called
void main()
{
    int a, b;
    b=fork(); // <-- current line of execution: 0 is returned to b
    printf("\nmy name is manish\n");
    printf("\n my name is anil\n");
    printf("\n the value of b = %d",b);
}

// what the parent process looks like after fork is called

