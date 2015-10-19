////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 16:02:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int main()
{
	
	int n,u,d,i,s;
	cin>>n>>u>>d;
	while(n!=0)
	{
		for(s=0,i=0;s<n;i++)
		{
			if(i%2==0)
				s+=u;
			else
				s-=d;
		}
		cout<<i<<endl;
		cin>>n>>u>>d;
	}
	
	return 0;
}
