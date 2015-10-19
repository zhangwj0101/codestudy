////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-16 20:08:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    long n;
    while(scanf("%ld",&n) != EOF)
	   if (n%8==2 || n%8==6)
		   printf("yes\n");
	   else
		   printf("no\n");
	return 0;
}
