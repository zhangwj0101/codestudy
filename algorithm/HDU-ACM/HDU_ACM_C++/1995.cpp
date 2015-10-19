////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-25 13:33:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1995
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int k,t,n;
	__int64 a;
	cin>>t;
	while(t--)
	{
		scanf("%d%d",&n,&k);
		a=1;
		a<<=n-k;
		printf("%I64d\n",a);
	}
	return 0;
}