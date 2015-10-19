////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-20 10:37:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a,b,m,n,ax,bx,w;
	while(scanf("%d%d%d",&a,&b,&n)!=EOF&&(a!=0&&b!=0))
	{
		for(m=1;n>0;n--)
			m*=10;
		ax=a%m;bx=b%m;
		if(ax==bx)
			w=1;
		else
			w=0;
		if(w)
			printf("-1\n");
		else
			printf("%d\n",a+b);
	}
}