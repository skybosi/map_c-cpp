#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include"map.h"
int main(int argc, char *argv[])
{
/*	if (argc < 2)
	{
		printf("usage:%s file.c keywords\n", argv[0]);
		exit(0);
	}
	*/
/*	char currentpath[PATHMAX];
	getcwd(currentpath,PATHMAX);
	printf("current path:: %s\n",currentpath);
	dir_traverse(currentpath);
	*/
	//char funchead[] = "%[^ ] %[^(](%[^)]";
	//char functail[] = "}";
	//get_key_line_number(argv[1],funchead,functail);
	get_key_line_number(argv[1]);

	return 0;
}
