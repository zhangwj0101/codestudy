////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-25 09:31:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a!=0||b!=0)
		{
			c=pow(10,c);
			if(a%c==b%c)
				cout<<-1<<endl;
			else
				cout<<a+b<<endl;
		}
		else
			break;

	}

	return 0;
}