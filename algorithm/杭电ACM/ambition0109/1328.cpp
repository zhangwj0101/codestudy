////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 18:28:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1328
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:332KB
//////////////////System Comment End//////////////////
/*
 * 1328.cpp
 *
 *  Created on: 2010-7-13
 *      Author: ambition
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n,t=0;
	string str;cin>>n;
	while(n--)
	{
		cin>>str;
		for(unsigned i=0;i<str.length();i++)
		{
			if(str[i]=='Z') str[i]='A';
			else str[i]++;
		}
		cout<<"String #"<<++t<<endl;
		cout<<str<<endl;
		cout<<endl;
	}
}
