////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 13:17:38
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2149
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,i,m,t;
	while(cin>>m>>n)
	{
		t=m%(1+n);
		if(t==0)
			cout<<"none"<<endl;
		else
		{
			if(m>n)
				cout<<t;
			else
			{
				for(i=t;i<=n;i++)
				{
					cout<<i;
					if(i<n)
						cout<<" ";
				}
			}
			cout<<endl;
		}
	}
   return 0;
}
