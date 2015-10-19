////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 18:29:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2163
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void main()
{
	string str;int t=0;
	while(cin>>str,str!="STOP")
	{
		string strr(str);
		reverse(strr.begin(),strr.end());
		if(strr==str) cout<<'#'<<++t<<": YES"<<endl;
		else cout<<'#'<<++t<<": NO"<<endl;
	}
}