#include"map.h"
#include<stdio.h>
void bub1()
{
	pMAP_P;
	printf("hello bub1\n");
	vMAP_P;
}
void bub4()
{
	pMAP_P;
	printf("hello bub4\n");
	bub1();
	vMAP_P;
}
void bub3()
{
	pMAP_P;
	printf("hello bub3\n");
	bub1();
	bub4();
	vMAP_P;
}
void bub2()
{
	pMAP_P;
	printf("hello bub2\n");
	bub3();
	vMAP_P;
}

int main(int argc, char *argv[])
{
	pMAP_P;
	printf("hello main\n");
	bub1();
	bub2();
	bub3();
	vMAP_P;
	return 0;
}
