#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>
int main ()
{
  pid_t child_pid;
 

  child_pid = fork ();
  if (child_pid > 0) {
	 printf("Parent process going to sleep! Good night!\n");	
		    sleep (2);
	printf("Parent process woke up!Hi good morning\n");
printf("\n the parent pid is %d",getpid());	
exit(0);
  }
  else {
printf("\n the child ppid is %d",getppid());
	  printf("Child process. Exit immediately.");
		    sleep (3);
printf("\n the child ppid is %d",getppid());
	//	    exit (0);
  }
	system("ps -axj");
  return 0;
}

/* go to pid and check the new ppid. It will have init user as its parent which means its an orphan. i am sorry to hear your loss.*/
