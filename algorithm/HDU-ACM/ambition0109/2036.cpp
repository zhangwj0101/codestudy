////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-13 20:52:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,x[101],y[101];
	double area;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<n;i++)
			scanf("%d%d",&x[i],&y[i]);
		x[i]=x[0];y[i]=y[0];
		for(area=0,i=0;i<n;i++)
			area+=(double)(x[i]*y[i+1]-x[i+1]*y[i])/2.;
		printf("%.1lf\n",area);
	}
}