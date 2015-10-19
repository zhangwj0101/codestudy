////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 18:11:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 2178.cpp
 *
 *  Created on: 2010-7-9
 *      Author: ambition
 */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<(int)pow(2.,(double)n)-1<<endl;
	}
}
