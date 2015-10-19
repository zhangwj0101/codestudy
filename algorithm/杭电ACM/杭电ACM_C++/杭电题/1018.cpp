////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-05-18 00:28:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:687MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long n,i,j,m;
	double s;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m;
		for(s=0,j=2;j<=m;j++)
		s+=log10(1.0*j);
		m=s;
		cout<<m+1<<endl;
	}
    return 0;
}