#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *calcFib( val)
{
    int count=0;
    int first=0,second=1,third=0;
    while(count<val)
    {
        third = first +second;
        printf("%d \n",third );
        first = second;
        second = third;
        count++;

    }   
    wait(1); 
    printf("Calculating fibonacci of  %d \n",val);
    return NULL;
}
  
  void *calcFac( val)
{
    int fac=1;
    while(val>0)
    {
        fac=fac*val;
        val--;
    }
    wait(1);
    printf("Calculating factoral %d  is %d  \n",val,fac);
    return NULL;
}
  
int main()
{
    pthread_t tid1,tid2;
    int i=10;
    printf("Before Thread \n");
    pthread_create(&tid1, NULL, calcFib, i);
    pthread_join(tid1, NULL);
    pthread_create(&tid2, NULL, calcFac, i);
    pthread_join(tid2, NULL);
    printf("After Thread\n");
    exit(0);
}





#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{

    printf("[currentP]: %d \n",getpid() );
    if(fork()==0)
    {
        printf("[childP1] %d [parent] %d \n",getpid(),getppid() );
    }
    if(fork()==0)
    {
        printf("[childP2] %d [parent] %d \n",getpid(),getppid() );
    }
}



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



#include<stdio.h>
#include<stdlib.h>
main()
{
    int n ,p,index[50],f[50],size;
    for(int i=0;i<50;i++)
        f[i]=0;
    // initiate f[50] with 0s
    printf("Enter the index \n" );
    scanf("%d",&p);
    // get index to start
    f[p]=1;
    // make index as 1
    printf("Enter the size of file \n");
    scanf("%d",&size);
    // get file size
    for (int i = 0; i < size; ++i)
    {
        /* code */
        scanf("%d",&index[i]);

    }
    // get all index
    for (int i = 0; i < size; ++i)
    {
        /* code */
        f[index[i]]=1;
    }
    // populate f[50] based on index taken as input
    printf("File Allocated\n");
    for (int i = 0; i < size; ++i)
    {
        /* code */
        printf("%d --> %d : %d \n",p,index[i],f[index[i]] );
    }
    // prnt the shit
}




#include<stdio.h>
#include<stdlib.h>
main()
{
int f[50],i,st,j,len,c;
//clrscr();
for(i=0;i<50;i++)
f[i]=0;
X:
printf("\n Enter the starting block & length of file");
scanf("%d%d",&st,&len);
for(j=st;j<(st+len);j++)
if(f[j]==0)
{
f[j]=1;
printf("\n%d->%d",j,f[j]);
}
else
{
printf("Block already allocated");
break;
}
if(j==(st+len))
printf("\n the file is allocated to disk");
printf("\n if u want to enter more files?(y-1/n-0)");
scanf("%d",&c);
if(c==1)
goto X;
else
exit(0);
  }





  #include<stdio.h>
#include<stdlib.h>
int main()
{
    int f[100],alreadyTakenCount,alreadyTaken,startBlock,length;
    for (int i = 0; i < 100; ++i)
    {
        /* code */
        f[i]=0;
    }
    printf("Enter how many blocks are allocated. \n");
    scanf("%d",&alreadyTakenCount);
    printf("alreadyTakenCount: %d\n",alreadyTakenCount );
    printf("Enter the blocks that are already taken.\n");
    for (int i = 0; i < alreadyTakenCount; ++i)
    {
        /* code */
        scanf("%d",&alreadyTaken);
        f[alreadyTaken]=1;
    }
    printf("Enter the starting block. \n");
    scanf("%d",&startBlock);
    printf("Starting block is : %d\n", startBlock);
    printf("Enter the length\n");
    scanf("%d",&length);
    for (int i = startBlock; i < startBlock+length; ++i)
    {
        /* code */
        if(f[i]==0)
        {
            f[i]=1;
            printf("[%d] -> [%d] \n",i,f[i] );
        }
        else
        {
            printf("File already allocated\n");
            length++;
        }
    }

}





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





#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
// A normal C function that is executed as a thread 
// when its name is specified in pthread_create()
void *add()
{
    int a=5,b=10;
    return a+b;        
}
  
void *prod1()
{
    int a=2,b=10;
    return a*b;        
}
  
int main()
{
    pthread_t tid1,tid2;
       void *status1,*status2;

    int i=10,sum,prod;
    printf("Before Thread \n");


    pthread_create(&tid1, NULL, add, NULL);
   pthread_join(tid1,  &status1);


    pthread_create(&tid2, NULL, prod1, NULL);
    prod = pthread_join(tid2,  &status2);

    printf("Sum is %d \n",status1);
    printf("Prod is %d \n",status2);
}




#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

int shared =1;
// pthread_mutex_t l; 
sem_t s;
void *fun1()
{
    printf("I am in fun1\n");
    int x,a=10,b=20;
    // pthread_mutex_lock(&l);
sem_wait(&s);
    x=shared;
    x++;
    sleep(1);
    shared=x;
     // pthread_mutex_unlock(&l);
     sem_post(&s);
    return a+b;
}

void *fun2()
{
    printf("I am in fun2\n");

    int y,a=2,b=3;
    // pthread_mutex_lock(&l);
sem_wait(&s);


    y=shared;
    y--;
    sleep(1);
    shared=y;
     // pthread_mutex_unlock(&l);
     sem_post(&s);
    return a*b;

}
int main()
{
    // pthread_mutex_init(&l, NULL);
    sem_init(&s,0,1);
    void *status1,*status2;
    pthread_t thread1, thread2;
    pthread_create(&thread1,NULL,fun1,NULL);
    pthread_create(&thread2,NULL,fun2,NULL);
    pthread_join(thread1, &status1);
    pthread_join(thread2, &status2);
    printf("Shared value is %d \n",shared );
    printf("Status value is %d \n",status1 );
    printf("Status2 value is %d \n",status2 );
}




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