////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 20:09:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:937MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<cstdio>
int main()
{
	__int64 n;
	while(scanf("%I64d",&n)==1)
	{
		n=n*(n+1)*(n+2)/6;
		printf("%I64d\n",n);
	}
	return 0;
}