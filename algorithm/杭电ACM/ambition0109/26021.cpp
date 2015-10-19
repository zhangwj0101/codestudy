////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 20:55:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2602
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[1001];
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
		for(i=0;i<=m;i++)
			num[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=m;j>=v[i];j--)
			{
				if(num[j-v[i]]+w[i]>num[j])
					num[j]=num[j-v[i]]+w[i];
			}
		}
		printf("%d\n",num[m]);
	}
}