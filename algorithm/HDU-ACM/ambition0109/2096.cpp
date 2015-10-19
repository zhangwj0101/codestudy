////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-09 16:30:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a,b,n;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",(a%100+b%100)%100);
	}
}