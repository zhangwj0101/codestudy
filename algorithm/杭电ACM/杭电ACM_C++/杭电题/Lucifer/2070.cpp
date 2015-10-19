////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 21:31:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstdio>
using namespace std;
int main()
{
	_int64 a,b,c;
	int n,k;
	cin>>n;
   while(n!=-1)
   {
	   a=0,b=1,k=0;
	   while(k<n)
	   {
		   c=a+b;
		   a=b;
		   b=c;
		   k++;
	   }
	   printf("%I64d\n",a);
	   cin>>n;
   }
   return 0;
}