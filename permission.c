#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
int
i;
struct stat buf;
char
*ptr;
for (i = 1; i < argc; i++) {
printf("%s: ", argv[i]);
if (lstat(argv[i], &buf) < 0) {
printf("lstat error");
continue;
}


if (S_IRUSR & buf.st_mode)
printf("user-read");
 if (S_IWUSR & buf.st_mode)
printf(ptr = "user-write");


}
exit(0);
}
