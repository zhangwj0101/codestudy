////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-28 08:39:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a<168){
			cout<<"CRASH "<<a<<endl;
			continue;
		}
		if(b<168){
			cout<<"CRASH "<<b<<endl;
			continue;
		}
		if(c<168){
			cout<<"CRASH "<<c<<endl;
			continue;
		}
		cout<<"No CRASH"<<endl;
	}
}