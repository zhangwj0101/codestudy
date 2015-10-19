////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-02 23:28:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	int c;
	do
	{
		c=b%a;
		b=a;
		a=c;
	}while(c);
	return b;
}
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<a*b/gcd(a,b)<<endl;
	}
   return 0;
}
