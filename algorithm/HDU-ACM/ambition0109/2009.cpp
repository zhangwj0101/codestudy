////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 19:49:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,m;
	double nf,sum;
	while(scanf("%d",&n)!=EOF)
	{
		for(scanf("%d",&m),nf=n,sum=0;m>0;m--)
			sum+=nf,nf=sqrt(nf);
		printf("%.2lf\n",sum);
	}
}