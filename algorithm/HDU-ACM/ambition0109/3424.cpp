////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 17:18:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3424
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void main()
{
	double sa,sb,ea,eb,ta,tb,suma,sumb,cost;
	while(1)
	{
		scanf("%lf%lf",&sa,&sb);
		ea=sa;eb=sb;
		if(sa==-1&&sb==-1) break;
		suma=0;sumb=0;
		while(scanf("%lf%lf",&ta,&tb),ta||tb)
		{
			if(tb>eb)
			{
				suma+=ea-sa;
				sumb+=sb-eb;
				sa=ta;sb=tb;
				ea=ta;eb=tb;
			}else{
				ea=ta;eb=tb;
			}
		}
		suma+=ea-sa;
		sumb+=sb-eb;
		cost=suma/sumb*eb;
		printf("%.0f\n",cost);
	}
}