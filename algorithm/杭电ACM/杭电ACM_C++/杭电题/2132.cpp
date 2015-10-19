////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-14 11:05:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	__int64 ans,n;
    while(scanf("%I64d",&n)==1&&n>=0)
    {
        ans=(n+1)*n/2-(n/3)*(3+(n/3)*3)/2+((n/3)*((n/3)+1)/2*((n/3)+1)*(n/3)/2)*27;
		printf("%I64d\n",ans);
    }
    return 0;
}