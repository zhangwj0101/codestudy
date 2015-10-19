////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-16 19:12:10
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1877
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a,b,n;
	char sum[17];
	while(scanf("%d",&n),n)
	{
		scanf("%d%d",&a,&b);
		itoa(a+b,sum,n);
		printf("%s\n",sum);
	}
}