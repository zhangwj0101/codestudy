////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 22:24:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,h[51],t,i,s,j=0;
	while(cin>>n&&n)
	{
		cout<<(j++?"\n":"");
		for(t=i=0;i<n;i++)
		{
			cin>>h[i];
			t+=h[i];
		}
		t=t/n;
		for(s=i=0;i<n;i++)
			if(h[i]>t)
				s+=h[i]-t;
		cout<<s<<endl;
	}
   return 0;
}