////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-04 10:27:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3361
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int t,i,num[1000];
	while(scanf("%d",&t)!=EOF)
	{
		for(i=0;i<t;i++)
			scanf("%d",&num[i]);
		for(i=0;i<t;i++)
			printf("%c",num[i]);
	}
}