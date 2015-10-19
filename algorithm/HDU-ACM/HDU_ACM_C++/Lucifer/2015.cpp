////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-11 14:03:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    int n,m,s,t,tt;
	while(cin>>n>>m)
	{
		s=m+1;
		tt=t=n/m;
		while(tt)
		{
			cout<<s;
			if(--tt)
				cout<<" ";
			s+=2*m;
		}
		if(n-t*m)
		{
			if(t)
				cout<<" ";
			cout<<n+t*m+1;
		}
		cout<<endl;
	}
   return 0;
}