#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#define size 4096
int main()
{
int n;
char buf[size];


int fid2=open("op.txt",O_RDWR); 
while((n=read(STDIN_FILENO,buf,size))>0)
if(write(fid2,buf,n)!=n)
printf("write error");

if(n<0)
printf("read error");

exit(0);
}
