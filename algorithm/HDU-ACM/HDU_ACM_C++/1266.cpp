////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-07 07:38:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1266
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
int main()
{
	int n,t,f,e,i,t1;
	cin>>n;
		while(n--)
		{
			cin>>t;
			if(t==0)
			{
				cout<<0<<endl;
				continue;
			}
			f=0;
			if(t<0)
			{
				f=1;
				t*=-1;
			}
			for(e=0;!(t%10);e++,t/=10);
			if(f)
				cout<<'-';
			t1=t;
			for(;t>0;t/=10)
				cout<<t%10;
			for(i=0;i<e;i++)cout<<'0';
			cout<<endl;
		}
	return 0;
}