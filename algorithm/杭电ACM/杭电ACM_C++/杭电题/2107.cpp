////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 00:07:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2107
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,m,i,t;
	cin>>n;
	while(n!=0)
	{
		m=0;
		for(i=0;i<n;i++)
		{
			cin>>t;
			if(t>m)
				m=t;
		}
		cout<<m<<endl;
		cin>>n;
	}
   return 0;
}

