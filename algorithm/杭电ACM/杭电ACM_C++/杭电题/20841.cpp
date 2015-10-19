////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-06 10:58:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<iostream>
#define M(a,b) (((a)>(b))?(a):(b))
using namespace std;
int a[100][100];
int main()
{
	int c,n,i,j,k;
	cin>>c;
	for(i=0;i<c;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
			for(k=0;k<=j;k++)
				cin>>a[j][k];
		for(j=n-2;j>=0;j--)
			for(k=0;k<=j;k++)
				a[j][k]+=M(a[j+1][k],a[j+1][k+1]);
		cout<<a[0][0]<<endl;
	}
	return 0;
}