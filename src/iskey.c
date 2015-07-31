#include <stdio.h>
#include <string.h>
//#include "isFunc.h"
char* keys[] = { "while","if","for","switch","printf","scanf","auto", "break", "case", "char", 
	"const", "continue", "default", "do", "double", "else", "enum", "extern", 
	"float",  "goto",  "int", "long", "register", "return", "short", "signed", 
	"sizeof", "static", "struct", "typedef", "union", "unsigned", "void", "volatile"};
int iskey(const char* testkey)
{		
	int i;
	char buf1[10] = {0};
	char buf2[100] = {0};
	char iskeyn[100] = {0};
	char patten[] = "%[^ ] %s";
	if(*testkey != ' ')
	{	
//		printf("%s\n",testkey);
		sscanf(testkey,patten,buf1,buf2);
		strcpy(iskeyn,buf2);
//		printf("buf1:%s\n",buf1);
//		printf("buf2:%s\n",buf2);
	}
	else
		strcpy(iskeyn,testkey);
	for(i = 0;i < 34; i++)
	{
		if(strstr(iskeyn,keys[i]))
		{
			printf("find : %s\n",keys[i]);
			return 1;
			break;
		}
	}
	return 0;
}
/*
int main()
{
	char test[] = "int    whie ";
	printf("%s\n",test);
	if(iskey(test))
		printf("NO function name,is a key words\n");
	else
		printf("is function name\n");
	return 0;
}*/
