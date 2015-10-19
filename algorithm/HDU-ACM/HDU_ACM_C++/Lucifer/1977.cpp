////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-29 20:03:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1977
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define P(x) (x)*(x)*(x)
int main()
{
	__int64 n;
	int t;
	cin>>t;
	while(t--)
	{
		scanf("%I64d",&n);
		printf("%I64d %I64d\n",P(n),P(n+1));
	}
	return 0;
}