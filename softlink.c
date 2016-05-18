#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc,char *argv[])
{
	char buffer[BUFFER_SIZE];
	printf("Creating Soft Link...\n");
	if(symlink(argv[1],argv[2])<0)
	{
		fprintf(stderr, "Error in creating a link\n");
		return 0;
	}

	readlink(argv[2],buffer,BUFFER_SIZE);
	printf("File Contents : %s\n",buffer);
}
