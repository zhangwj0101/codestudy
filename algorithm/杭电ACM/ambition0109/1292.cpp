////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 14:20:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1292
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

__int64 s[30][30],b[30];
void main()
{
	s[1][1]=1;b[1]=1;
	for(int i=2;i<=25;i++){
		b[i]=0;
		for(int j=1;j<=i;j++){
		b[i]+=s[i][j]=j*s[i-1][j]+s[i-1][j-1];
		}
	}
	int t;
	for(cin>>t;t;t--)
	{
		int n;
		cin>>n;
		cout<<b[n]<<endl;
	}
}