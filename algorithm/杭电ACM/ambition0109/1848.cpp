////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-06 21:43:54
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1848
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[16]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597};
int SG[1005];
void main()
{
	int m,n,p,j,i,sum;
	int hash[1004];
	for(i=0;i<=1004;i++)
	{
		for(j=0;j<=100;j++)
			hash[j]=0;
		for(j=0;j<16;j++)
		{
			if(i-num[j]>=0)
				hash[SG[i-num[j]]]=1;
		}
		for(j=0;j<=100;j++)
			if(hash[j]==0)
			{
				SG[i]=j;
				break;
			}
	}
	while(scanf("%d%d%d",&m,&n,&p))
	{
		if(m==0&&n==0&&p==0)
			break;
		sum=SG[m]^SG[n]^SG[p];
		if(sum==0)
			printf("Nacci\n");
		else
			printf("Fibo\n");                  
	}  
}