////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-02 10:14:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1984
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,m,i;
	string s;
	while(cin>>n)
	{
		for(i=1;i<=n;i++)
		{
			cin>>m>>s;
			s.erase(m-1,1);
			cout<<i<<" "<<s<<endl;
		}
	}
  return 0;
}