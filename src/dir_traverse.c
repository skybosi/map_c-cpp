#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<string.h>
#include"map.h"
#define FILENM_MAX 512
int dir_traverse(const char *dir_name)
{
	DIR *dirp = opendir(dir_name);
	if(!dirp) {
		perror("opendir");
		return -1;
	}
	struct stat st;
	struct dirent *dir;
	char fullpath[FILENM_MAX];
	//char funchead[] = "%*[^(](%[^)]";
//	char funchead[] = "%[^ ] %[^(](%[^)]";
//	char functail[] = "}";
	while((dir = readdir(dirp)) != NULL) 
	{
		sprintf(fullpath, "%s/%s", dir_name, dir->d_name); //获取全局路径
		if(dir->d_type == 4 )
		{
			if(!strcmp(dir->d_name, ".") || // 考虑当前目录和上级目录，否则会死循环
					!strcmp(dir->d_name, "..")) 
			{
				continue;
			}
			else
				dir_traverse(fullpath); // 递归遍历子目录
		}
		else
		{
			if(strstr(fullpath,".c"))
			{
				printf("%s\n", fullpath); // 打印路径
				//get_key_line_number(fullpath,funchead,functail);
				get_key_line_number(fullpath);
			}
			else if(strstr(fullpath,".cpp"))
			{
				printf("%s\n", fullpath); // 打印路径
				//get_key_line_number(fullpath,funchead,functail);
				get_key_line_number(fullpath);
			}
			else
				continue;
			if(lstat(fullpath, &st) < 0) 
			{
				perror("lstat");
				continue;
			}
		}
	}
	closedir(dirp);
	return 0;
}
