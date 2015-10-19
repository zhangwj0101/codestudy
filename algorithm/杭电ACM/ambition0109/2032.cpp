////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-09 16:56:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,num[31];
	while(scanf("%d",&n)!=EOF)
	{
		num[0]=1;
		printf("%d\n",num[0]);
		for(i=1;i<30;i++)
			num[i]=0;
		for(i=1;i<n;i++)
		{
			for(j=i;j>0;j--)
				num[j]=num[j]+num[j-1];
			for(j=0;j<i;j++)
				printf("%d ",num[j]);
			num[j]=1;
		printf("%d\n",num[j]);
		}
		printf("\n");
	}
}