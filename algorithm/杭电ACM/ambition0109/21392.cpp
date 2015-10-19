////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 17:36:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<stdio.h>

main()
{
	__int64 n;
	while(scanf("%I64d",&n)!=EOF){
		printf("%I64d\n",(n+2)*(n+1)*n/6);
	}
}
