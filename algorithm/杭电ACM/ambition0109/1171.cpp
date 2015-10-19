////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-21 20:01:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:1171MS
////Run memory:712KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int half[150000],temp[150000];
main()
{
	int n,m,i,j,t,k,num[50],value[50],sum;
	while(scanf("%d",&n),n>=0)
	{
		if(n)
		{
			for(i=0,sum=0;i<n;i++)
			{
				scanf("%d%d",&value[i],&num[i]);
				sum+=value[i]*num[i];
			}
			for(i=0;i<=sum/2;i++)
			{temp[i]=0;half[i]=0;}
			for(i=0,j=0;j<=num[0];i+=value[0],j++)
				half[i]=1;
			for(i=1;i<n;i++)
			{
				for(j=0;j<=sum/2;j++)
					for(k=0,t=0;k+j<=sum/2&&t<=num[i];k+=value[i],t++)
						temp[k+j]+=half[j];
					for(j=0;j<=sum/2;j++)
					{half[j]=temp[j];temp[j]=0;}
			}
			for(i=sum/2;half[i]==0;i--);
			printf("%d %d\n",sum-i,i);
		}
		else
			printf("0 0\n");
	}
}