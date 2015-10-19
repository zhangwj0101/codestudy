////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-10 19:01:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2052
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int h,w,i,j;
	while(scanf("%d%d",&w,&h)!=EOF)
	{
		printf("+");
		for(i=0;i<w;i++)
			printf("-");
		printf("+\n");
		for(j=0;j<h;j++)
		{
			printf("|");
			for(i=0;i<w;i++)
				printf(" ");
			printf("|\n");
		}
		printf("+");
		for(i=0;i<w;i++)
			printf("-");
		printf("+\n\n");
	}
}