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
	
//exit(0);
  }
  else {

	  printf("Child process. Exit immediately.");
		    //sleep (3);
	printf("child's pid is %d",getpid());
		    exit (0);
  }
	system("ps");
  return 0;
}

/* you will see <defunct> in the child pid*/
