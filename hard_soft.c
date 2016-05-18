#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main( int argc, char* *argv )
{
 	struct stat old_file_stats , new_file_stats;
 	int ch,n;
 	printf("1.Hard Link\n 2.Soft Link\n");
	switch(ch)
	{
		case 1:	printf("Creating Hard Link ...\n");
				n = link(argv[1],argv[2]);
				break;
		case 2: printf("Creating Soft Link ...\n");
				n = symlink(argv[1],argv[2]);
				break;
	}

	if(n<0)
	{
		fprintf(stderr,"Error Linking\n");
		return 1;
	}
	
	if(lstat(argv[1], &old_file_stats) < 0 || (lstat(argv[2],&new_file_stats) < 0))
	{
		fprintf(stderr,"Error Creating stat");
		return 1;
	}

	printf(" Old File Inode: %ld\n",old_file_stats.st_ino);
	printf(" New File Inode: %ld\n",new_file_stats.st_ino);
	//printf("Numbe of Hard Link : %ld\n", old_file_stats.st_nlink);
	
}
