////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 17:29:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:288KB
//////////////////System Comment End//////////////////
/*
 * 1555.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	int n,k;
	while(cin>>n>>k,n||k)
	{
		int count=0;
		for(;n/k;n=n/k+n%k)
			count+=n-n%k;
		count+=n%k;
		cout<<count<<endl;
	}
	return 0;
}
