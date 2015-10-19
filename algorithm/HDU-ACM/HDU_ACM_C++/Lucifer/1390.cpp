////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-09 07:52:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1390
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,n,p,i;
	while(cin>>t)
	while(t--)
	{
		cin>>n;
		for(i=p=0;n;n/=2,i++)
			if(n%2)
				cout<<(p++?" ":"")<<i;
		cout<<endl;
	}
	return 0;
}