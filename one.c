#include <stdio.h>
main ()
{
 int pid, pid2,pid3;
 printf ("\nI'm the original process with PID %d and PPID %d.\n\n", getpid (), getppid ());
 pid = fork ();                     /* Duplicate process. Child and parent continue from here */

     printf ("I'm the child process with PID %d and PPID %d.\n", 
        getpid (), getppid ());
     // pid2= fork();      
    
   
   pid2=fork();
    printf ("I'm the child's child with PID %d and PPID %d.\n", 
        getpid (), getppid ());    
 pid3 = fork();
  printf ("I'm the child's child with PID %d and PPID %d.\n", 
        getpid (), getppid ());  
}