////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 19:10:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a,b,sum1,sum2,n,tmp;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a>b)
			tmp=a,a=b,b=tmp;
		for(sum1=0,sum2=0,n=a;n<=b;n++)
		{
			if(n%2)
				sum1+=n*n*n;
			else
				sum2+=n*n;
		}
		printf("%d %d\n",sum2,sum1);
	}
}