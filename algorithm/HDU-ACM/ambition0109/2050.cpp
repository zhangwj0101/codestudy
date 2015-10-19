////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-17 21:49:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,num,ans;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&num),i=2,ans=2;i<=num;i++)
		{
			ans=ans+4*(i-1)+1;
		}
		printf("%d\n",ans);
	}
}