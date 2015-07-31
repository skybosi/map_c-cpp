#ifndef _MAP_PROGRAM_H_
#define _MAP_PROGRAM_H_
#include<stdio.h>
/*char** keys = { "do", "else", "for",  "if", "struct", "switch", "while"};*/
static int deep = 0;
int tmpfd;
int nul;
void deep_fun(int deep2);
void hide_output(void);
void recover_output(int tmpfd);
#define P_func printf("\033[1;31m%s\033[0m\n",__func__);
#define P_LINE printf("\033[1;31m%s\033[0m",__LINE__);
#define P_FILE printf("%d",__FILE__);
#define pMAP_P {if(deep != 0)recover_output(tmpfd);int deep2 = deep; deep_fun(deep2); P_func; hide_output(); deep++;}
#define vMAP_P {deep--;}
#endif

