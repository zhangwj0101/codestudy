////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 18:55:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:552KB
//////////////////System Comment End//////////////////
#pragma warning(disable:4786)
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n,m,i,t;
	set<int> s;
	set<int>::iterator it;
	while(cin>>n>>m)
	{
		for(i=0;i<m+n;i++)
		{
			cin>>t;
			s.insert(t);
		}
		it=s.begin();
		cout<<*it;
		for(it++;it!=s.end();it++)
			cout<<" "<<*it;
		cout<<endl;
		s.clear();
	}
  return 0;
}