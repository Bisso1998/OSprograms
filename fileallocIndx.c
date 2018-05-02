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