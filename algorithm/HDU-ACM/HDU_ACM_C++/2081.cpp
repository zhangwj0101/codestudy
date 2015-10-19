////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 21:37:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2081
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
	_int64 a;
	int n,i,a1;
	cin>>n;
   for(i=0;i<n;i++)
   {
	   scanf("%I64d",&a);
	   a1=a%100000+600000;
	   cout<<a1<<endl;
   }
   return 0;
}