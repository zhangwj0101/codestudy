////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-23 18:31:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2134
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,R;
	double r1,r2;
	while(scanf("%d",&R),R)
	{
		r1=sqrt((double)R/3.*(double)R);
		r2=sqrt((double)R/3.*2.*(double)R);
		printf("%.3lf %.3lf\n",r1,r2);
	}
}