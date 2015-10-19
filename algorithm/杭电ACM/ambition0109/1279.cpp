////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-03 15:38:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1279
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

void main()
{
	int n,m,t;
	for(cin>>n;n>0;n--)
	{
		cin>>m;t=m;
		while(t!=1)
		{
			if(t%2){
				cout<<t;
				break;
			}
			if(t%2) t=3*t+1;
			else t/=2;
		}
		if(t==1){cout<<"No number can be output !"<<endl;continue;}
		while(t!=1)
		{
			if(t%2) t=3*t+1;
			else t/=2;
			if(t%2&&t!=1){
				cout<<' '<<t;
			}
		}
		cout<<endl;
	}
}