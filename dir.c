#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	DIR *dp;
	struct dirent *dir;

	dp = opendir(".");
	if(dp)
	{
		while ((dir = readdir(dp)) != NULL)
		{
			printf("%ld\t%d\t%s\t%ld\n",dir->d_ino,dir->d_type,dir->d_name,(long)dir->d_off);
		}

	}
	closedir(dp);
}