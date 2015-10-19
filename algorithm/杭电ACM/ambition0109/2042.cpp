////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-09 17:15:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2042
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,peach,i;
	for(scanf("%d",&i);i>0;i--)
	{
		scanf("%d",&n);
		for(peach=3;n>0;n--)
			peach=(peach-1)*2;
		printf("%d\n",peach);
	}
}