////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-04 22:21:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1418
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	__int64 m,n;
	while(scanf("%I64d%I64d",&n,&m)==2)
	{
		if(!m&&!n)break;
		printf("%I64d\n",n+m-2);
	}
   return 0;
}