////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-05 15:11:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2398
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:312KB
//////////////////System Comment End//////////////////
/*
 * 2398.cpp
 *
 *  Created on: 2010-7-5
 *      Author: ambition
 */

#include<iostream>
using namespace std;

int main()
{
	double a,b,c;
	while(cin>>a>>b>>c)
	{
		int count=0;
		while(a<c){
			a=a*(100.+b)/100;
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
