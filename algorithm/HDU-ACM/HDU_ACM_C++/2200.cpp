////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-04 22:19:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2200
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	__int64 a,n;
	while(scanf("%I64d",&n)==1)
	{
		a=1;
		a<<=(n-1);
		printf("%I64d\n",1+(n-2)*a);
	}
   return 0;
}