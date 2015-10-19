////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-03 17:06:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:368KB
//////////////////System Comment End//////////////////
/*
 * 1196.cpp
 *
 *  Created on: 2010-7-3
 *      Author: ambition
 */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m,t;
	while(cin>>n,n){
		t=0;
		while(!(n&1)){
			n>>=1;t++;
		}
		cout<<(int)pow(2.,(double)t)<<endl;
	}
	return 0;
}
