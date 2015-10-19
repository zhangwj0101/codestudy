////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 14:14:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:1512KB
//////////////////System Comment End//////////////////
#include<iostream>
#define N 100001
using namespace std;
int a[N];
struct S
{
	int m;
	int s;
	int e;
}b[N];
int main()
{
	int n,i,k,t,m;
	cin>>t;
	for(k=0;k<t;k++)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		b[0].m=a[0];
		b[0].s=b[0].e=0;
		for(i=1;i<n;i++)
		{
			b[i].e=i;
			if(b[i-1].m<0)
			{
				b[i].m=a[i];
				b[i].s=i;
			}
			else
			{
				b[i].m=b[i-1].m+a[i];
				b[i].s=b[i-1].s;
			}

		}
		for(m=0,i=1;i<n;i++)
		{
			if(b[m].m<b[i].m)
			{
				m=i;
			}
		}
		cout<<"Case "<<k+1<<":"<<endl;
		cout<<b[m].m<<" "<<b[m].s+1<<" "<<b[m].e+1<<endl;
		if(k<t-1)
			cout<<endl;
	}
 return 0;
}