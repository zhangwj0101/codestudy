////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 17:40:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",(int)(((__int64)(n+1)*(__int64)(n+2)*(__int64)n)/6));
	}
}
