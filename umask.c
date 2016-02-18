#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
int
main(void)
{
int fd1;
mode_t mod1;

umask(0653);
fd1=creat("q.txt",0777);

system("ls -li q.txt");

exit(0);
}
