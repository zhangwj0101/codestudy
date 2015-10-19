////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 20:36:47
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,num,i;
	double sum;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&num);
		for(i=1,sum=0;i<=num;i++)
			sum+=pow(-1,i-1)/(double)i;
		printf("%.2lf\n",sum);
	}
}