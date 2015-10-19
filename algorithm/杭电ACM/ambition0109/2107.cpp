////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-16 15:50:50
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2107
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,p,m;
	while(scanf("%d",&n),n)
	{
		
		for(scanf("%d",&m);n>1;n--)
		{
			scanf("%d",&p);
			if(p>m)
				m=p;
		}
		printf("%d\n",m);
	}
}