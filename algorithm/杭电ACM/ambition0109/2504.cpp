////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-12 18:50:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2504
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,x,i,j,t,a,b,k;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&a,&b);
		for(i=2;;i++)
		{
			t=b*i;
			m=(a<t?a:t);
			for(x=m,j=1;m>1;j++)
			{
				x=m/j;
				if(!((a%x)||(t%x)))
					break;
			}
			if(x==b)
				break;
		}
		printf("%d\n",t);
	}
}