////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-15 16:26:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1092
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{ 
	int n,i,a,sum;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			sum+=a;
		}
		printf("%d\n",sum);
	}
 } 
