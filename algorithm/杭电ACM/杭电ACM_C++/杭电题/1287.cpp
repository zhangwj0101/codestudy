////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-05 07:18:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1287
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma warning(disable:4786)
#include <iostream>
#include<set>
using namespace std;
int main()
{
	int a[1000],i,n,t;
	set<int> s,s2;
	set<int>::iterator it;
	while(cin>>n)
	{
		s.clear();
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s.insert(a[i]);
		}
		for(i=1;i<=26;i++)
		{
			s2.clear();
			for(it=s.begin();it!=s.end();it++)
				s2.insert(*it^i);
			if(s2.size()==26&&(*s2.begin()==1)&&(*(--s2.end())==26))
				break;
		}
		t=i;
		for(i=0;i<n;i++)
			cout<<(char)(a[i]^t+64);
		cout<<endl;
	}
	return 0;
}