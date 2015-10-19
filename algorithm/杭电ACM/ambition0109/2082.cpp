////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 14:56:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[51],temp[51],count[27];
main()
{
	int n,i,j,k,sum;
	for(scanf("%d",&n);n>0;n--)
	{
		for(i=0;i<51;i++)
			num[i]=temp[i]=0;
		num[0]=1;
		for(i=1;i<27;i++)
			scanf("%d",&count[i]);
		for(i=1;i<27;i++)
		{
			for(j=0;j<51-i;j++)
			{
				if(num[j]!=0)
				for(k=1;k<=count[i]&&j+k*i<51;k++)
					temp[j+k*i]+=num[j];
			}
			for(j=0;j<51;j++)
			{num[j]+=temp[j];temp[j]=0;}
		}
		for(i=1,sum=0;i<51;i++)
			sum+=num[i];
		printf("%d\n",sum);
	}
}