////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 13:52:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2013
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,peach;
	while(scanf("%d",&n)!=EOF)
	{
		for(peach=1;n>1;n--)
			peach=(peach+1)*2;
		printf("%d\n",peach);
	}
}