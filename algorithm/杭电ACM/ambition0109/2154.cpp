////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 14:58:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2154
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int num[1001],t[1001],n,i=2;
	while(scanf("%d",&n),n)
	{
		for(num[1]=0,t[1]=1;i<=n;i++)
		{
			t[i]=t[i-1]*2;
			t[i]%=10000;
			num[i]=t[i]+10000-num[i-1];
			num[i]%=10000;
		}
		printf("%d\n",num[n]);
	}
}