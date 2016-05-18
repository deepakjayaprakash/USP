#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int c=0;
int  main()
{
	int ch,i,n=10;
	pid_t  pid;
	printf("1 - fork()\n2 - vfork()\n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:	pid = fork();
			break;
		case 2: pid = vfork();
			break;
		default : printf("Invalid Choice\n");
	}	
	{
		if(pid == 0)
			{
				printf("Child Process\n");
				c = c+10;
				printf("Value of c : %d\n",c);
			}
		else 
			{
				printf("Parent Process\n");
				c = c+10;
				printf("Value of c : %d\n",c);
			}
	}
		
}
