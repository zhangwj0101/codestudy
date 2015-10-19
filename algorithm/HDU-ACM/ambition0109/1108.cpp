////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-20 08:35:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:184KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a,b,c,m;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		for(m=c=(a>=b?a:b);;m+=c)
			if(m%a==0&&m%b==0)
				break;
		printf("%d\n",m);
	}
}