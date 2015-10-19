////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 14:48:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2123
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 2123.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int num[10][10];
int main()
{
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++)
			num[i][j]=i*j;
	int n;
	for(cin>>n;n;n--)
	{
		int m;cin>>m;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(j-1) cout<<' ';
				cout<<num[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
