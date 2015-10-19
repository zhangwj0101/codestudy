////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 16:29:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2575
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,t,count[9]={1,2,2,4,4,6,6,10,10};
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		for(t=m;t/10;t/=10);
		printf("%d\n",count[t-1]);
	}
}