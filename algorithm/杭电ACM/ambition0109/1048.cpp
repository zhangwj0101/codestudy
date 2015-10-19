////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 19:28:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:300KB
//////////////////System Comment End//////////////////
/*
 * 1048.cpp
 *
 *  Created on: 2010-7-9
 *      Author: ambition
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string com,str;bool t=false;
	char temp[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
	while(getline(cin,com),com!="ENDOFINPUT")
	{
		if(com=="START"){t=true;}
		else if(com=="END"){
			t=false;
			cout<<str<<endl;
		}
		else{
			str=com;
			if(t){
				for(unsigned i=0;i<str.length();i++)
					if(str[i]<='Z'&&str[i]>='A')
					str[i]=temp[str[i]-'A'];
			}
		}
	}
}
