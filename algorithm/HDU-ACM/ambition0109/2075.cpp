////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-12 20:36:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,a,b;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&a,&b);
		if(a%b)
			printf("NO\n");
		else
			printf("YES\n");
	}
}