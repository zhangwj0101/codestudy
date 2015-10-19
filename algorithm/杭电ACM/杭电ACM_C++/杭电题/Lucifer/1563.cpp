////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-08 21:46:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#pragma warning(disable:4786)
#include<iostream>
#include<set>
#include<map>
using namespace std;
int main()
{
	int t,i,n;
	set<int> ss;
	map<int,int> mm;
	set<int>::iterator it;
	while(cin>>n&&n)
	{
		for(i=0;i<n;i++)
		{
			cin>>t;
			ss.insert(t);
			mm[t]++;
		}
		for(it=ss.begin();it!=ss.end();it++)
			if(mm[*it]==1)
			{
				cout<<*it<<endl;
				break;
			}
		mm.clear();
		ss.clear();
	}
	return 0;
}