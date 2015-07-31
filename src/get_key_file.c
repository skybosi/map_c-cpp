#include"isFunc.h"
#include<stdio.h>
#include<string.h>

//int get_key_line_number(const char *file, const char *headkey,const char* tailkey)
int get_key_line_number(const char *file)
{
	char outfile[128] = {0};
	strcpy(outfile,file);
	FILE *fpi = NULL,*fpo = NULL;
	char string[1024] = { 0 };
	//	size_t result = 0;
	int line = 0;
	if (file == NULL)
	{
		printf("filename not give or keywords not give!\n");
		return -1;
	}
	if (*file == '\0')
	{
		printf("file is not exist or no key!\n");
		return -2;
	}
	fpi = fopen(file, "r");
	if (fpi == NULL)
	{
		perror("Error in opening file");
		return -3;
	}
	strcat(outfile, ".c");
	fpo = fopen(outfile, "w");
	if (fpo == NULL)
	{
		perror("Error out opening file");
		return -4;
	}
	do
	{
		line++;
		memset(string, 0, sizeof(string));
		fgets(string, 1024, fpi);
		if(isfunc(string))
		{
			fputs(string,fpo);
			fputs("\tpMAP_P;\n",fpo);
			printf("\033[1;31m%d\t:%s\033[0m",line,string);
		}
		else
		{
			//printf("Not patten!\n");
			fputs(string,fpo);
		}
	}while (!feof(fpi));
	line = 0;
	fclose(fpi);
	fclose(fpo);
	fpi = NULL;
	fpo = NULL;
	return 0;
}
