////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-04 19:47:16
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2399
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:328KB
//////////////////System Comment End//////////////////
/*
 * 2399.cpp
 *
 *  Created on: 2010-10-4
 *      Author: administrator
 */

#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
using namespace std;

int main()
{
	string str;
	int Sum=0,cnt=0;
	bool flag=true;
	while(getline(cin,str)){
		stringstream ss(str);
		while(ss>>str){
			if(flag){
				cnt++;
				if(str[0]=='A') Sum+=4;
				else if(str[0]=='B') Sum+=3;
				else if(str[0]=='C') Sum+=2;
				else if(str[0]=='D') Sum+=1;
				else if(str[0]=='F') Sum+=0;
				else flag=false;
			}
		}
		if(flag){
			printf("%.2lf\n",(double)Sum/(double)cnt);
		}else{
			puts("Unknown letter grade in input");
		}
		Sum=0;cnt=0;
		flag=true;
	}
}
