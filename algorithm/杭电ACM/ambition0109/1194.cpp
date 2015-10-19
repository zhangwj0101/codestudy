////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-17 19:12:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1194
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
/*
 * 1194.cpp
 *
 *  Created on: 2010-7-17
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	int t;cin>>t;
	int sum,diff;
	while(t--){
		cin>>sum>>diff;
		int a,b;
		a=(sum+diff)/2;
		b=(sum-diff)/2;
		if(a+b==sum&&a-b==diff&&a>=0&&b>=0) cout<<a<<" "<<b<<endl;
		else cout<<"impossible"<<endl;
	}
}
