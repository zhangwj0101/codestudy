////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 14:59:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,num[100],min;
	while(scanf("%d",&n),n)
	{
		scanf("%d",&num[1]);
		min=1;
		for(i=2;i<=n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]<num[min])
				min=i;
		}
		if(min-1)
			num[0]=num[min],num[min]=num[1],num[1]=num[0];
		printf("%d",num[1]);
		for(i=2;i<=n;i++)
			printf(" %d",num[i]);
		printf("\n");
	}
}