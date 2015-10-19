////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 19:55:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2105
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:168KB
//////////////////System Comment End//////////////////
/*
 * 2105.cpp
 *
 *  Created on: 2010-7-9
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

int main()
{
	int t;
	double x1,x2,x3,y1,y2,y3,xx,yy;
	while(scanf("%d",&t),t)
	while(t--)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
		xx=(x1+x2+x3)/3.;
		yy=(y1+y2+y3)/3.;
		printf("%.1lf %.1lf\n",xx,yy);
	}
}
