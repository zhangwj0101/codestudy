////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 15:29:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1701
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:324KB
//////////////////System Comment End//////////////////
/*
 * 1701.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	int t;
	for(cin>>t;t--;)
	{
		double a,b;
		cin>>a>>b;
		int i;
		for(i=2;;i++)
		{
			int aa,bb;
			aa=(int)((double)i*a/100.);
			bb=(int)((double)i*b/100.);
			if(bb-aa) break;
		}
		cout<<i<<endl;
	}
}
