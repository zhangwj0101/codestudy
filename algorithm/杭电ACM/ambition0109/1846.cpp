////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 10:12:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1846
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int step[1001];
main()
{
	int t,n,m,i,j;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&n,&m);
		step[0]=0;
		for(i=1;i<=m;i++)
			step[i]=1;
		for(i=m+1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				if(step[i-j]==0)
					break;
			if(j==m+1)
				step[i]=0;
			else
				step[i]=1;
		}
		if(step[n])
			printf("first\n");
		else
			printf("second\n");
	}
}