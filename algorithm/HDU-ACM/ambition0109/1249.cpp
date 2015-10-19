////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 17:37:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1249
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[10000];
main()
{
	int n,m,i=1;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		for(num[0]=2;i<m;i++)
			num[i]=i*6+num[i-1];
		printf("%d\n",num[m-1]);
	}
}