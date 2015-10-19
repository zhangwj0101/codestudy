////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-10 18:42:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<stdlib.h> 
main()
{
	int n;
	char o[15];
	while(scanf("%d",&n)!=EOF)
	{
		itoa(n,o,2);
		printf("%s\n",o);
	}
}