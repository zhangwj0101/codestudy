////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2009-03-28 12:16:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2634
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:160KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
void main()
{
	int t,n,i;
	double a,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(sum=i=0;i<n;i++)
		{
			scanf("%lf",&a);
			sum+=a;
		}
		printf("The average M = %.10f.\n",sum/n);
	}
}