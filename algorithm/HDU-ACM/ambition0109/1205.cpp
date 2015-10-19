////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-29 21:00:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,num,max;
	__int64 sum;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),max=0,sum=0;m>0;m--)
		{
			scanf("%d",&num);
			if(num>max)
				max=num;
			sum+=num;
		}
		if(max<=(sum-sum/2))
			printf("Yes\n");
		else
			printf("No\n");
	}
}