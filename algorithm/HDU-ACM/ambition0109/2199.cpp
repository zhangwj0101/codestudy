////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-12 10:17:45
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2199
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#define f(x) 8.*x*x*x*x+7.*x*x*x+2.*x*x+3.*x+6.
main()
{
	int n;
	double y,min,max,half;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf",&y);
		min=0.;
		max=100.;
		if(y<f(0.0)||y>f(100.0))
		{
			printf("No solution!\n");
			continue;
		}
		half=f(50.0);
		while(fabs(half-y)>0.000001)
		{
			if(half>y) max=(min+max)/2.;
			else min=(min+max)/2.;
			half=f((min+max)/2.);
		}
		printf("%.4lf\n",(min+max)/2.);
	}
}