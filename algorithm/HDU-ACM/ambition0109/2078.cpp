////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 20:04:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2078
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:288KB
//////////////////System Comment End//////////////////
/*
 * 2078t.cpp
 *
 *  Created on: 2010-7-18
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	int t,n,k;cin>>t;
	while(t--)
	{
		int num,min;
		cin>>n>>k;min=100;
		for(int i=0;i<n;i++)
		{
			cin>>num;
			if(num<min) min=num;
		}
		cout<<(100-min)*(100-min)<<endl;
	}
}
