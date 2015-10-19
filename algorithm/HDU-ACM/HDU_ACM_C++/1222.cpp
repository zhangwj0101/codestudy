////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-06 07:52:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1222
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int a,b,r,m,n,cn;
	while(cin>>cn)
	{
		while(cn--)
		{
			cin>>m>>n;
			a=m,b=n;
			while(b)
			{
				r=a%b;
				a=b;
				b=r;
			}
			if(a==1)
				cout<<"NO\n";
			else
				cout<<"YES\n";
		}
	}
	return 0;
}