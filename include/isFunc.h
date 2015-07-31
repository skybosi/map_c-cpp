#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isfunc(char* string);
int instr(const char* teststr,const char key);
int matchcurves(const char* teststr,const char* decollator,char* result[3]);
void matchfree(char* result[]);
