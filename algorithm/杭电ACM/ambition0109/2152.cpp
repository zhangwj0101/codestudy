////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-21 19:20:54
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2152
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,t,k,num[100],fruit[101],temp[101];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&t,&k);
			num[i]=k-t;m-=t;
		}
		if(m>=0)
		{
			for(i=0;i<=m;i++)
			{temp[i]=0;fruit[i]=0;}
			for(i=0;i<=num[0];i++)
				fruit[i]=1;
			for(i=1;i<n;i++)
			{
				for(j=0;j<=num[i];j++)
					for(k=0;k+j<=m;k++)
						temp[k+j]+=fruit[k];
				for(j=0;j<=m;j++)
				{fruit[j]=temp[j];temp[j]=0;}
			}
		}
		else
		{m=0;fruit[0]=0;}
		printf("%d\n",fruit[m]);
	}
}