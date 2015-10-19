////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-12 18:40:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2078
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,t,m,min,tt;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(min=100;n--;)
		{
			cin>>tt;
			if(min>tt)
				min=tt;
		}
		cout<<(100-min)*(100-min)<<endl;
	}
   return 0;
}