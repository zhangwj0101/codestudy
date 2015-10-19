////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-07 11:38:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int i,n,m,ans;
	while(scanf("%d%d",&n,&m),n||m)
	{
		for(i=0,ans=1;i<m;i++)
		{
			ans*=n;
			ans%=1000;
		}
		printf("%d\n",ans);
	}
}