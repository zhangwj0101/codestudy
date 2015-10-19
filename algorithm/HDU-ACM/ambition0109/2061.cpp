////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-10 15:55:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2061
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;

void main()
{
	int t,n,tt,i;
	double s,c,sumcs,sumc;
	char str[31];
	for(scanf("%d",&t);t>0;t--)
	{
		for(scanf("%d",&n),getchar(),i=0,tt=0,sumc=0,sumcs=0;i<n;i++)
		{
			scanf("%s %lf%lf",str,&c,&s);
			if(s<60) tt=1;
			if(tt) continue;
			sumc+=c;sumcs+=c*s;
		}
		if(tt) printf("Sorry!\n");
		else printf("%.2lf\n",sumcs/sumc);
		if(t!=1) printf("\n");
	}
}