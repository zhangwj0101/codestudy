////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-02 17:10:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1214
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:492KB
//////////////////System Comment End//////////////////
/*
 * 1214.cpp
 *
 *  Created on: 2010-7-2
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int num[32768];
int main()
{
	num[2]=0;num[3]=1;
	for(int i=4;i<32768;i++)
		num[i]=num[i-2]+i-2;
	int n;
	while(cin>>n)
		cout<<num[n]<<endl;
	return 0;
}
