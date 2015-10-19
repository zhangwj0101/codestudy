////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 19:16:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1785
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:172KB
//////////////////System Comment End//////////////////
/*
 * 1785.cpp
 *
 *  Created on: 2010-8-20
 *      Author: ambition
 */

#include<cstdio>
#include<cstdlib>
using namespace std;

struct Acmer
{
	double x;
	double y;
}acmer[101];
int cmp(const void *a,const void *b)
{
	double ka=(*(Acmer*)a).x/(*(Acmer*)a).y;
	double kb=(*(Acmer*)b).x/(*(Acmer*)b).y;
	return ka>kb?-1:1;
}
int main()
{
	int n;
	while(scanf("%d",&n),n>=0){
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&acmer[i].x,&acmer[i].y);
		}
		qsort(acmer,n,sizeof(Acmer),cmp);
		printf("%.1lf %.1lf",acmer[0].x,acmer[0].y);
		for(int i=1;i<n;i++){
			printf(" %.1lf %.1lf",acmer[i].x,acmer[i].y);
		}
		puts("");
	}
}
