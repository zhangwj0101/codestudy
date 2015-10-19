////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 20:39:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4068KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[1001][1001];
main()
{
	int n,m,i,j,t,v[1001],w[1001];
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		for(i=0;i<n;i++)
			scanf("%d",&v[i]);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(j>=v[i-1])
				{
					if(num[i-1][j-v[i-1]]+w[i-1]>num[i-1][j])
						num[i][j]=num[i-1][j-v[i-1]]+w[i-1];
					else num[i][j]=num[i-1][j];
				}
				else num[i][j]=num[i-1][j];
			}
		}
		printf("%d\n",num[n][m]);
	}
}