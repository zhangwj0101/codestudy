////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-12 19:27:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*
 * 1088.cpp
 *
 *  Created on: 2010-7-12
 *      Author: ambition
 */

#include<iostream>
#include<string>
using namespace std;

const string hr="--------------------------------------------------------------------------------";
int main()
{
	string str;
	int count=0;
	while(cin>>str)
	{
		if(str=="<br>"){
			cout<<endl;
			count=0;
		}else if(str=="<hr>"){
			if(count) cout<<endl;
			cout<<hr;cout<<endl;count=0;
		}else{
			if(count+str.length()>79){
				cout<<endl;cout<<str;
				count=str.length();
			}else if(count==0){
				cout<<str;
				count=str.length();
			}
			else{
				cout<<' '<<str;
				count+=str.length()+1;
			}
		}
	}
	cout<<endl;
}
