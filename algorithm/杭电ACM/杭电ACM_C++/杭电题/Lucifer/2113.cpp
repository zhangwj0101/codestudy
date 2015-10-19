////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 00:35:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,m,t,a[1000],i=0,j;
	while(cin>>n)
	{
		m=0;
		while(n>0)
		{
			t=n%10;
			if(t%2==0)
				m+=t;
			n/=10;
		}
		a[i++]=m;
	}
	for(j=0;j<i-1;j++)
		cout<<a[j]<<endl<<endl;
	cout<<a[j]<<endl;
   return 0;
}
