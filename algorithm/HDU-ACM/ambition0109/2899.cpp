////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-12 10:51:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
#define f(x,y) 6.*pow(x,7.)+8.*pow(x,6.)+7.*pow(x,3)+5.*pow(x,2)-y*x
main()
{
	int n;
	double y,min,max,ft,st;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%lf",&y);
		min=0.;
		max=100.;
		ft=f((min*2.+max)/3.,y);
		st=f((min+max*2.)/3.,y);
		while(max-min>0.0000001)
		{
			if(ft<st) max=(min+max*2.)/3.;
			else min=(min*2.+max)/3.;
			ft=f((min*2.+max)/3.,y);
			st=f((min+max*2.)/3.,y);
		}
		printf("%.4lf\n",ft);
	}
}