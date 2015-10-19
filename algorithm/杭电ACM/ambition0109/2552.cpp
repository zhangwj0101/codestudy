////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 13:38:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2552
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n;
	double s,u,v,t,m;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf%lf",&s,&u);
		t=atan(1./s)-atan(1./u);
		m=tan(t);
		v=1./m;
		printf("%.0lf\n",v*u-s*u-s*v);
	}
}