////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 13:57:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2085
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i;
	__int64 num1[34],num2[34];
	num1[0]=1,num2[0]=0;
	for(i=1;i<34;i++)
	{
		num1[i]=num1[i-1]*3+num2[i-1]*2;
		num2[i]=num1[i-1]+num2[i-1];
	}
	while(scanf("%d",&n),n+1)
	{
		printf("%I64d, %I64d\n",num1[n],num2[n]);
	}
}