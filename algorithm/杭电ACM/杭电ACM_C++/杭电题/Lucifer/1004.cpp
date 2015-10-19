////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 00:15:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma   warning(disable:4786) 
#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
int main()
{
	int n;
	set<string> s;
	map<string,int> m;
	set<string>::iterator i,max;
	string c;
	while(cin>>n&&n)
	{
		s.clear();
		m.clear();
		while(n--)
		{
			cin>>c;
			s.insert(c);
			m[c]++;
		}
		for(max=i=s.begin();i!=s.end();i++)
			if(m[*i]>m[*max])
				max=i;
		cout<<*max<<endl;
	}
   return 0;
}