////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-27 09:52:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1701
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	double p,q;
	int n,i;
	cin>>n;
	while(n--)
	{
		cin>>p>>q;
		for(i=1;i<10010;i++)
			if(int(q*i/100)>int(p*i/100))
			{
				cout<<i<<endl;
				break;
			}
	}
	return 0;
}