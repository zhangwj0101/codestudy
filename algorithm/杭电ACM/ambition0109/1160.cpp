////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-24 17:13:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1160
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i=0,j,m,n,num[3][1000],g[1000],t,max,mmax;
	while(scanf("%d%d",&num[0][i],&num[1][i])!=EOF)
	{
		g[i]=i;
		i++;
	}
	for(m=i,i=0;i<m-1;i++)
		for(j=i+1;j<m;j++)
			if(num[0][g[i]]<num[0][g[j]])
			{t=g[i];g[i]=g[j];g[j]=t;}
	for(i=0;i<m;i++)
	{
		num[2][g[i]]=1;
		for(j=i-1,max=0;j>0;j--)
		{
			if(num[1][g[i]]>num[1][g[j]]&&num[0][g[i]]!=num[0][g[j]])
			{
				n=num[2][g[j]];
				if(n>max)
					max=n;
			}
		}
		num[2][g[i]]+=max;
		if(num[2][g[i]]>mmax)
			mmax=num[2][g[i]];
	}
	printf("%d\n",mmax);i=m;t=10000;
	for(max=mmax;max;max--)
		for(;i>0;i--)
		{
			if(num[2][g[i-1]]==max&&num[1][g[i-1]]<t)
			{
				t=num[1][g[i-1]];
				printf("%d\n",g[i-1]+1);
				break;
			}
		}
}