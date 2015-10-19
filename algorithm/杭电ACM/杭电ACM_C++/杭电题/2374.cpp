////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-08-30 21:20:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2374
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,t;
	__int64 p,s;
	while(cin>>n&&n)
	{
		p=1,s=0;
		while(n--)
		{
			cin>>t;
			s+=t*p;
			p<<=1;
		}
		printf("%I64d\n",s);
	}
   return 0;
}