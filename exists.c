#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
int i;
for(i=1;i<argc;i++){
int res=access(argv[i], F_OK);
 if (res < 0)
printf("%s -file does not exist\n",argv[i]);
else
printf("%s - file exists\n",argv[i]);
}
return 0;
}