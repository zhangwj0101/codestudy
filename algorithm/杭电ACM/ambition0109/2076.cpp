////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 12:51:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,i,j,h,m,s;
	double hh,mm,minus;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d%d",&h,&m,&s);
		if(h>=12) h-=12;
		hh=((double)h+((double)m+(double)s/60.)/60.)/12.*360.;
		mm=((double)m+(double)s/60.)/60.*360.;
		minus=fabs(hh-mm)>180.?360.-fabs(hh-mm):fabs(hh-mm);
		printf("%d\n",(int)minus);
	}
}