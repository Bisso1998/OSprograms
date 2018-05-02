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