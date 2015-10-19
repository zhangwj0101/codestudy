////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 12:48:47
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[10001],w[500],v[500];
main()
{
	int n,m,e,f,t,i,j;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d%d",&e,&f);
		m=f-e;
		for(scanf("%d",&n),i=0;i<n;i++)
			scanf("%d%d",&v[i],&w[i]);
		num[0]=0;
		for(i=1;i<=m;i++)
			num[i]=-1;
		for(i=0;i<n;i++)
		{
			for(j=w[i];j<=m;j++)
			{
				if(num[j-w[i]]!=-1&&num[j]!=-1)
				{if(num[j-w[i]]+v[i]<num[j]) num[j]=num[j-w[i]]+v[i];}
				else if(num[j-w[i]]!=-1&&num[j]==-1)
				{num[j]=num[j-w[i]]+v[i];}
			}
		}
		if(num[m]!=-1)
		printf("The minimum amount of money in the piggy-bank is %d.\n",num[m]);
		else
			printf("This is impossible.\n");
	}
}