////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 11:46:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2147
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m;
	while(scanf("%d%d",&n,&m),m||n)
	{
		if(n%2&&m%2)
			printf("What a pity!\n");
		else
			printf("Wonderful!\n");
	}
}