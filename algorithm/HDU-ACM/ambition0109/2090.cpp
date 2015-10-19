////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-07 15:48:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	char name[100];
	double n,m,all;
	all=0;
	while(scanf("%s %lf%lf",name,&n,&m)!=EOF)
	{
		all+=n*m;
	}
	printf("%.1lf\n",all);
}