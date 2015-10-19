////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 15:38:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,o=1,num,sum;
	while(scanf("%d",&n),n>0)
	{
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d",&num);
			sum+=num;
		}
		printf("Sum of #%d is %d\n",o++,sum);
	}
}