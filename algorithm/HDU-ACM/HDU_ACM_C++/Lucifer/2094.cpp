////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-26 12:50:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma warning(disable:4786)
#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;
int main()
{
	int c,f;
	string t,n;
	set<string> s;
	set<string>::iterator i;
	map<string,int> m;
	while(cin>>c&&c)
	{
		m.clear();
		s.clear();
		while(c--)
		{
			cin>>t>>n;
			s.insert(t);
			s.insert(n);
			m[t]+=1;
			m[n]=-500001;
		}
		for(f=0,i=s.begin();i!=s.end();i++)
		{
			if(m[*i]>=0)
			{
				f++;
			}
		}
		if(f==1)
				cout<<"Yes\n";
		else
			cout<<"No\n";
	}
    return 0;
}