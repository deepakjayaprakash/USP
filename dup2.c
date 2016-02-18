#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void)
{
int fd=open("b.txt",O_RDWR);
int fd3;



int fd2=open("first.c",O_RDONLY,0777);

char buf[1000];
int n=read(fd2,buf,100);
fd3=dup2(fd,1);
lseek(1, 0, SEEK_SET);
int n2=write(fd3,buf,100);




exit(0);
}
