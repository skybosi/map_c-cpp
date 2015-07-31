/*****************************************************
 ** Name         : sscanf.c 
 ** Author       : gzshun
 ** Version      : 1.0
 ** Date         : 2011-12
 ** Description  : sscanf function
 ******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void sscanf_test(void);

static void sscanf_test(void)
{
	int ret;
	char *string;
	int  digit;
	char buf1[255];
	char buf2[255];
	char buf3[255];
	char buf4[255];
	char buf5[255];

	/*6.获取指定字符中间的字符串*/
	//char patten[] = "%*[^(]%[(]%*[^)]%[)]";
	char patten[] = "%[^ ] %[^(]%s";
//	char patten[] = "%[^ ] %[^(]%[(]%[^)]%[)]%s";
	//string = "int main(int argc,char** argv)";
	//string = "int main(asda)";
	string = "	if(a>0)";
	ret = sscanf(string, patten, buf1,buf2,buf3,buf4,buf5);
	printf("6.6666:%d\n", ret);
	printf("6.string=%s\n", string);
	printf("6.buf1=|%s|\n\n", buf1);
	printf("6.buf2=|%s|\n\n", buf2);
	printf("6.buf3=|%s|\n\n", buf3);
	printf("6.buf4=|%s|\n\n", buf4);
	printf("6.buf5=|%s|\n\n", buf5);

	/*7.指定要跳过的字符串*/
	string = "iosVSandroid";
	ret = sscanf(string, "%[a-z]VS%[a-z]", buf1, buf2);
	printf("6.6666:%d\n", ret);
	printf("7.string=%s\n", string);
	printf("7.buf1=%s, buf2=%s\n\n", buf1, buf2);

	/*9.提取邮箱地址*/
	string = "Email:beijing@sina.com.cn";
	ret = sscanf(string, "%[^:]:%[^@]@%[^.].%s", buf1, buf2, buf3, buf4);
	printf("6.6666:%d\n", ret);
	printf("9.string=%s\n", string);
	printf("9.buf1=%s, buf2=%s, buf3=%s, buf4=%s\n\n", buf1, buf2, buf3, buf4);
	/*
	 **执行结果:
	 **9.buf1=Email, buf2=beijing, buf3=sina, buf4=com.cn
	 */

	/*10.过滤掉不想截取或不需要的字符串--补充,
	 **在%号后面加一*号,代表过滤这个字符串,不读取
	 */
	string = "android iphone wp7";
	ret = sscanf(string, "%s %*s %s", buf1, buf2);
	printf("6.6666:%d\n", ret);
	printf("10.string=%s\n", string);
	printf("10.buf1=%s, buf2=%s\n\n", buf1, buf2);
	/*
	 **执行结果:
	 **10.android wp7
	 */
}

int main(int argc, char **argv)
{
	sscanf_test();

	return 0;
}

/*
 **测试程序
 **环境:
 **Linux ubuntu 2.6.32-24-generic-pae #39-Ubuntu SMP Wed Jul 28 07:39:26 UTC 2010 i686 GNU/Linux
 **gcc version 4.4.3 (Ubuntu 4.4.3-4ubuntu5)
 **
 gzshun@ubuntu:~/c/sscanf$ gcc sscanf.c -o sscanf
 gzshun@ubuntu:~/c/sscanf$ ./sscanf
 1.string=china beijing 123
 1.ret=3, buf1=china, buf2=beijing, digit=123

 2.string=123456789
 2.buf1=12345

 3.string=123/456
 3.buf1=123

 4.string=123abcABC
 4.buf1=123abc

 5.string=0123abcABC
 5.buf1=0123, buf2=abc, buf3=ABC

 6.string=ios<android>wp7
 6.buf1=android

 7.string=iosVSandroid
 7.buf1=ios, buf2=android

 8.string=android-iphone-wp7
 8.buf1=android, buf2=iphone, buf3=wp7

 9.string=Email:beijing@sina.com.cn
 9.buf1=Email, buf2=beijing, buf3=sina, buf4=com.cn

 10.string=android iphone wp7
 10.buf1=android, buf2=wp7
 */

