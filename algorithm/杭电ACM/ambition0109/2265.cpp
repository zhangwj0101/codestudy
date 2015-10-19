////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 20:12:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2265
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
/*
 * 2265.cpp
 *
 *  Created on: 2010-7-9
 *      Author: ambition
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while(getline(cin,str))
	{
		for(unsigned i=0;i<str.length();i++)
		{
			if(str[i]==' '){
				str.erase(i,1);
				i--;
			}
		}
			for(unsigned i=0;i<str.length();i++)
				if(!((i+1)%3)) cout<<str[i];
			for(unsigned i=0;i<str.length();i++)
				if(!((i+1)%2)&&((i+1)%3)) cout<<str[i];
			for(unsigned i=0;i<str.length();i++)
				if((i+1)%2&&(i+1)%3) cout<<str[i];
			cout<<endl;
	}
}
