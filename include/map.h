#ifndef _MAP_PROGRAM_H_
#define _MAP_PROGRAM_H_
#include<stdio.h>
#include<unistd.h>
#include<regex.h>


//static int deep = 0;			//深度值
void deep_fun(int deep2);		//确定函数调用时的深度
#define PATHMAX 500
#define P_func printf("\033[1;31m%s\n\033[0m",__func__);
#define P_LINE printf("\033[1;31m%s\033[0m",__LINE__);
#define P_FILE printf("%d",__FILE__);
#define pMAP_P {int deep2 = deep; deep_fun(deep2); P_func; deep++;}
#define vMAP_P {deep--;}
int dir_traverse(const char *dir_name);
//int get_key_line_number(const char *file, const char *headkey,const char *tailkey);
int get_key_line_number(const char *file);
int iskey(const char* testkey);
#endif

