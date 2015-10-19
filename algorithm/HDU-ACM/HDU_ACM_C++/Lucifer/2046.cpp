////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 00:49:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2046
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	_int64 a,b,c;
	int i,n;
	while(cin>>n)
	{
		a=1,c=b=2;
		for(i=2;i<n;i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		if(n==1)
			printf("%I64d\n",a);
		else
			printf("%I64d\n",c);
	}
   return 0;
}