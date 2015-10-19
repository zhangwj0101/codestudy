////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 19:38:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1391
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a==b||a-2==b){
			if(a&1) cout<<a+b-1<<endl;
			else cout<<a+b<<endl;
		}else cout<<"No Number"<<endl;
	}
}