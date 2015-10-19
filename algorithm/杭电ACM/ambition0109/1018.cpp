////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 12:05:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,i,t;
	double d;
	for(scanf("%d",&t);t>0;t--)
	{
		scanf("%d",&n);
		for(i=1,d=0;i<=n;i++)
			d+=log10(i);
		printf("%d\n",(int)d+1);
	}
}