#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void)
{
int fd=open("first.c",O_RDONLY);
int fd2;
dup2(fd,fd2);
printf("%d \t %d",fd,fd2);


char buf[100];
int n=read(fd,buf,10);
int n2=write(1,buf,10);




exit(0);
}
