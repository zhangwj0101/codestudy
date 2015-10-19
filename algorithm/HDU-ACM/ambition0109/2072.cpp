////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-18 18:40:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:328KB
//////////////////System Comment End//////////////////
/*
 * 2072.cpp
 *
 *  Created on: 2010-7-18
 *      Author: ambition
 */

#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

vector<string> astr;
int main()
{
	int count;string str;
	while(getline(cin,str),str!="#"){
		count=0;astr.clear();
		stringstream ss(str);
		string word;
		while(ss>>word){
			unsigned i;
			for(i=0;i<astr.size();i++)
				if(word==astr[i]) break;
			if(i==astr.size()) astr.push_back(word);
		}
		cout<<astr.size()<<endl;
	}
}
