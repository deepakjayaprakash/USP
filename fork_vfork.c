#include<stdio.h>
#include<stdlib.h>
int main()
{
	int ppid,pid,i=10;
	pid=vfork();
	if(pid<0)
	printf("\nCannot fork!");
	if(pid!=0)
	{
		printf("\nParent Process! %d\n",getpid());
		printf("\ni = %d",i);
	}	
	else
	{
		printf("\nChild Process! %d\n",getpid());
		i=13;
		printf("\ni = %d",i);		
		exit(0);
	}
}
