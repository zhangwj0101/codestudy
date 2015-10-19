////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-17 13:27:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#define PI 3.1415927
void main()
{
	double r;
	while(scanf("%lf",&r)==1)
	{
		double v=(r*r*r*PI*4.)/3.;
		printf("%.3lf\n",v);
	}
}