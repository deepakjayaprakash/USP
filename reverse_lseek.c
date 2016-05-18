#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main( int argc, char* *argv )
{
	int fd,pos,n,i;
	char buffer[1];
	fd = open(argv[1],O_RDWR|O_CREAT,0777);
	n = lseek(fd,0,SEEK_END);
	for(i=0;i<=n;i++)
	{
		pos = lseek(fd,-i,SEEK_END);
		read(fd,buffer,1);
		write(STDOUT_FILENO,buffer,1);
	}
	printf("\n");
}