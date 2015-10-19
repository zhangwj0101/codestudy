////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-11 18:55:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2212
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:284KB
//////////////////System Comment End//////////////////
/*
 * 2212.cpp
 *
 *  Created on: 2010-8-11
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int fac[10];
int main()
{
	fac[0]=1;
	for(int i=1;i<10;i++){
		fac[i]=fac[i-1]*i;
	}
	for(int i=1;i<1000000;i++){
		int t=i,sum=0;
		sum=fac[t%10];
		while(t/=10){
			sum+=fac[t%10];
		}
		if(sum==i) cout<<i<<endl;
	}
}
