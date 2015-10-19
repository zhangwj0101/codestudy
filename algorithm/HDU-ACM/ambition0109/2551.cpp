////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 13:11:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2551
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int sum[260];
main()
{
	int n,m,i;
	for(i=1,sum[0]=0;i<252;i++)
	{
		sum[i]=sum[i-1]+i*i*i;
	}
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		for(i=0;i<252;i++)
		{
			if(sum[i]>=m)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}