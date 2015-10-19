////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 19:03:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1799
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:15872KB
//////////////////System Comment End//////////////////
/*
 * 1799.cpp
 *
 *  Created on: 2010-7-13
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int num[2001][2001];
int main()
{
	num[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		num[i][0]=1;
		for(int j=1;j<=i;j++)
			num[i][j]=(num[i-1][j-1]+num[i-1][j])%1007;
	}
	int m,n,t;cin>>t;
	while(t--)
	{
		cin>>m>>n;
		cout<<num[n][m]<<endl;
	}
}
