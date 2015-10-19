////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 15:10:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2156
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i;
	double sum;
	while(scanf("%d",&n),n)
	{
		sum=n;
		for(i=2;i<=n;i++)
			sum+=(double)(n-i+1)*2/(double)i;
		printf("%.2lf\n",sum);
	}
}