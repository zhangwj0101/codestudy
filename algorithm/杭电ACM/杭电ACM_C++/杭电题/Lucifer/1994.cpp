////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 17:44:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1994
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int q,t;
	double y,e,f,g,s1,s2;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>y>>q>>e>>f>>g;
			s1=y*(1+e/100*q/365)*(1+g/100);
			cout<<s1<<endl;
			s2=y*(1+f/100*(q+365)/365);
			cout<<s2<<endl;
		}
	}
  return 0;
}