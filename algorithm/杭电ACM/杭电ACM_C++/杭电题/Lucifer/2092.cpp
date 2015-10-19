////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-26 23:09:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m,s;
	float t;
	cin>>n>>m;
	while(n!=0||m!=0)
	{
		t=n*n-4*m;
		if(t>0)
		{
			s=(int)sqrt(t);
			if(t==s*s)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		else
			cout<<"No"<<endl;
		cin>>n>>m;
	}
   return 0;
}

