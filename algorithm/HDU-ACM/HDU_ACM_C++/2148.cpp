////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-09 13:02:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2148
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
	int n,t,x[1000],i,j,k,l;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>k;
		for(j=0;j<n;j++)
			cin>>x[j];
		l=0;
		for(j=0;j<n;j++)
			if(x[j]>x[k-1])
				l++;
		cout<<l<<endl;
	}
   return 0;
}
