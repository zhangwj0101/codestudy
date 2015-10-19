////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-15 16:30:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1093
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{ 
	int icase,n,i,j,a,sum;
	scanf("%d",&icase);
	for(i=0;i<icase;i++)
	{
		sum=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			sum+=a;
		}
	printf("%d\n",sum);
	}
 } 
