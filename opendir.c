#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) 
{
	if(argc != 2) 
	{
		fprintf(stderr,"usage: %s <directory>\n",argv[0]);
		return(1);
	}

	DIR *dir = opendir(argv[1]);
	if(dir == NULL) 
	{
		printf("opendir with %s failed\n",argv[1]);
		return(1);
	}

	struct dirent *entry;
	while((entry = readdir(dir)) != NULL) 
	{
		printf("%s\n",entry->d_name);
	}

	closedir(dir);
	return(0);
}
