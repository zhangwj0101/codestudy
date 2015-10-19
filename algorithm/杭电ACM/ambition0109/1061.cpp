////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-20 09:35:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,w,i,m;
	for(scanf("%d",&i);i>0;i--)
	{
		scanf("%d",&n);
		m=n%10;
		if(n>4)
			n=n%4+4;
		for(w=1;n>0;n--)
		{
			w*=m;
			w=w%10;
		}
		printf("%d\n",w);
	}
}