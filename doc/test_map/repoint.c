#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include"map.h"
void hide_output(void)
{
	tmpfd = dup(STDOUT_FILENO);
	nul = open("/dev/null",O_RDWR | O_CREAT|O_APPEND ,0644);
	if(nul < 0)
	{
		printf("open dev/null error\n");
		return;
	}
	dup2(nul, STDOUT_FILENO);
	close(nul);
}
void recover_output(int tmpfd)
{
	dup2(tmpfd,STDOUT_FILENO);
	close(tmpfd);
}
