////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-08 20:54:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<cstdio>
int main()
{int n;
__int64 a;
while(scanf("%d",&n)==1)
{
	if(n==1)
		puts("3");
	else
	{
	a=(__int64)1<<n;
	a+=(n%2)?-2:2;
	printf("%I64d\n",a);
	}
}
return 0;
}