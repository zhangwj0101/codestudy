////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-04 17:04:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1220
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,n;
	while(scanf("%d",&n)==1)
	{
		t=n*n*n;
		printf("%d\n",t*(t-1)/2-3*n*n*(n-1));
	}
   return 0;
}