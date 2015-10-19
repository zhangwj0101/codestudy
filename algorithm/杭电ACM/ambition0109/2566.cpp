////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 16:06:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2566
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,t,i,j,k,sum,count;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0,count=0;i<=n;i++)
		{
			for(j=0;j<=n-i;j++)
			{
				k=n-i-j;
				sum=k+2*j+5*i;
				if(sum==m)
					count++;
			}
		}
		printf("%d\n",count);
	}
}