////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-03 16:38:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:372KB
//////////////////System Comment End//////////////////
/*
 * 1060.cpp
 *
 *  Created on: 2010-7-3
 *      Author: ambition
 */

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,m;
	double g;
	double h;
	for(cin>>n;n>0;n--)
	{
		cin>>m;
		g=m*log10((double)m);
		g=g-(long long)g;
		h=pow(10.,(double)g);
		cout<<(int)h<<endl;
	}
	return 0;
}
