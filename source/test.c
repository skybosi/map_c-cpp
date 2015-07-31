#include"map.h"
#include<stdio.h>
void bub1()
{
	printf("hello bub1\n");
}
void bub4()
{
	printf("hello bub4\n");
	bub1();
}
void bub3()
{
	printf("hello bub3\n");
	bub1();
	bub4();
}
void bub2()
{
	printf("hello bub2\n");
	bub3();
}

int main(int argc, char *argv[])
{
	printf("hello main\n");
	bub1();
	bub2();
	bub3();
	return 0;
}
