////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 01:09:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	_int64 a,b,c;
	int i,j,n,m;
	cin>>m;
	for(j=0;j<m;j++)
	{
		cin>>n;
		a=1,b=1,c=2;
		for(i=2;i<n;i++)
		{
			a=b;
			b=c;
			c=a+b;
		}
		if(n==1)
			printf("%I64d\n",a);
		else 
			printf("%I64d\n",b);
	}
   return 0;
}