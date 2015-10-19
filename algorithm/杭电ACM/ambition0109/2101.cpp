////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-13 19:38:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2101
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i,a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if((a+b)%86)
			printf("no\n");
		else
			printf("yes\n");
	}
}