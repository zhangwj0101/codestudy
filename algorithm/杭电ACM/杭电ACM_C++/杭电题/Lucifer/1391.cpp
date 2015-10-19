////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-09 21:40:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1391
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,a,b,t;
	cin>>n;
    while(n--)
    {
		cin>>a>>b;
		if(!(a==b||a-b==2))
			cout<<"No Number\n";
		else
		{
			t=a*2;
			if(a==b)
			{
				if(a%2)
					t--;
			}
			else
				if(a%2)
					t-=3;
				else
					t-=2;
			cout<<t<<endl;
		}
    }
    return 0;
}