////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-19 19:30:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1994
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:324KB
//////////////////System Comment End//////////////////
/*
 * 1994.cpp
 *
 *  Created on: 2010-7-19
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	int t;cin>>t;
	while(t--)
	{
		double y,e,f,g;
		int q;
		cin>>y>>q>>e>>f>>g;
		double w1=(double)y*(1.+f*(double)(q+365)/36500.);
		double w2=(double)y*(1.+e*(double)q/36500.)*(1.+g/100.);
		cout<<w2<<endl;
		cout<<w1<<endl;
	}
}
