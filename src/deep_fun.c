#include"map.h"
#include<stdio.h>
void deep_fun(int deep2)
{
	while(deep2--)
	{
		if(deep2 == 0)
			printf(" |__");
		else
			printf("    ");
	}
}
