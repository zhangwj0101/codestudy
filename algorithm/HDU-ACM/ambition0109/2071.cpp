////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-12 20:48:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i;
	double max,num;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),max=0,i=0;i<m;i++)
		{
			scanf("%lf",&num);
			if(num>max)
				max=num;
		}
		printf("%.2lf\n",max);
	}
}