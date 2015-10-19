////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 19:42:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2674
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:296KB
//////////////////System Comment End//////////////////
/*
 * 2674.cpp
 *
 *  Created on: 2010-7-19
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int Fuc[2009];
int main()
{
	Fuc[0]=1;
	for(int i=1;i<2009;i++){
		Fuc[i]=Fuc[i-1]*i;
		if(Fuc[i]>=2009) Fuc[i]%=2009;
	}
	int n;
	while(cin>>n)
	{
		if(n>=2009) cout<<0<<endl;
		else cout<<Fuc[n]<<endl;
	}
}
