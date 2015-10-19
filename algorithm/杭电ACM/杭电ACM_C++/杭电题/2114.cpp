////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-16 21:03:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2114
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{int n;
while(cin>>n)
{
n=n%10000;
n=((n*n+n)/2)%10000;
printf("%04d\n",(n*n)%10000);
}
return 0;
}