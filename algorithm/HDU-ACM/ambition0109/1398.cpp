////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-20 20:41:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1398
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[300],temp[300];
main()
{
	int n,i,j,k;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<=n;i++)
			num[i]=1,temp[i]=0;
		for (i=2;i<=17;i++)
		{
			for(j=0;j<=n;j++)
				for (k=0;k+j<=n;k+=i*i)
					temp[j+k]+=num[j];
			for(j=0;j<=n;j++)
			{num[j]=temp[j];temp[j]=0;}
		}
		printf("%d\n",num[n]);
	}
}