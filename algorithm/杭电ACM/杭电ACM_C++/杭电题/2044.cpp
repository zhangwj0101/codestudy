////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 01:16:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2044
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
	int i,j,n,m,n1,n2;
	cin>>m;
	for(j=0;j<m;j++)
	{
		cin>>n1>>n2;
		n=n2-n1;
		a=1,b=c=2;
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