////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 23:18:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double n,m,s;
	char t[20];
	s=0;
	while(cin>>t)
	{
		cin>>n>>m;
		s+=n*m;
	}
	printf("%.1f\n",s);
   return 0;
}

