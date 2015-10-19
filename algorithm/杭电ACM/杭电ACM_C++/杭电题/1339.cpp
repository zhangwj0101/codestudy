////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-09 07:43:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1339
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int t,n,o,p;
	while(cin>>t)
	while(t--)
	{
		cin>>n;
		for(o=n,p=0;o%2==0;p++,o/=2);
		cout<<o<<" "<<p<<endl;
	}
	return 0;
}