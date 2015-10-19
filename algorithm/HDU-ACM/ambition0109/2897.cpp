////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-15 10:18:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2897
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int main()
{
	int n,m,q;
	while(cin>>q>>n>>m)
	{
		q%=(n+m);
		if(q==0) cout<<"WIN"<<endl;
		else if(q<=n) cout<<"LOST"<<endl;
		else cout<<"WIN"<<endl;
	}
}