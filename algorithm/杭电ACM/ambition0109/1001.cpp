////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-18 16:58:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(m=0;n>0;n--)
			m+=n;
		printf("%d\n\n",m);
	}
}