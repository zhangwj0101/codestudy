////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 12:06:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,num[1000],sum;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0,sum=1;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]%2)
				sum*=num[i];
		}
		printf("%d\n",sum);
	}
}