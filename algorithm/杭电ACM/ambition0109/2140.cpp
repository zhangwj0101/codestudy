////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-10 20:08:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2140
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:336KB
//////////////////System Comment End//////////////////
/*
 * 2140.cpp
 *
 *  Created on: 2010-7-10
 *      Author: ambition
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		for(unsigned i=0;i<str.length();i++){
			if(str[i]=='b') str[i]=' ';
			else if(str[i]=='q') str[i]=',';
			else if(str[i]=='t') str[i]='!';
			else if(str[i]=='m') str[i]='l';
			else if(str[i]=='i') str[i]='e';
			else if(str[i]=='c') str[i]='a';
			else if(str[i]=='a') str[i]='c';
			else if(str[i]=='e') str[i]='i';
			else if(str[i]=='l') str[i]='m';
		}
		cout<<str<<endl;
	}
}
