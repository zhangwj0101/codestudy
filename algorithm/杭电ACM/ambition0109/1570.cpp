////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 15:58:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1570
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 1570.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int fuc[11]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
int a[11][11],c[11][11];
int main()
{
	for(int i=1;i<11;i++)
		for(int j=1;j<=i;j++)
		{
			a[i][j]=fuc[i]/fuc[i-j];
			c[i][j]=a[i][j]/fuc[j];
		}
	int n;
	for(cin>>n;n--;){
		char ch;int aa,bb;
		cin>>ch>>aa>>bb;
		if(ch=='A') cout<<a[aa][bb]<<endl;
		else if(ch=='C') cout<<c[aa][bb]<<endl;
	}
	return 0;
}
