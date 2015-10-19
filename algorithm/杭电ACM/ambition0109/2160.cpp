////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 15:26:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2160
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,t,num[2];
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		num[0]=1,num[1]=0;
		for(i=1;i<m;i++)
		{
			t=num[0];
			num[0]+=num[1];
			num[1]=t;
		}
		printf("%d\n",num[0]+num[1]);
	}
}