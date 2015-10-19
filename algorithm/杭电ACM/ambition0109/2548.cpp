////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 12:55:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2548
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n;
	double u,v,w,l;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf%lf%lf%lf",&u,&v,&w,&l);
		printf("%.3lf\n",l/(u+v)*w);
	}
}