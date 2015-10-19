////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-24 17:19:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2700
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
/*
 * 2700.cpp
 *
 *  Created on: 2010-9-24
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

char str[35];
int main()
{
	while(gets(str),strcmp(str,"#")){
		int len=(int)strlen(str),cnt=0;
		for(int i=0;i<len-1;i++){
			if(str[i]=='1') cnt++;
		}
		if(cnt&1&&str[len-1]=='e'){
			str[len-1]='1';
		}else if(cnt&1&&str[len-1]=='o'){
			str[len-1]='0';
		}else if(str[len-1]=='e'){
			str[len-1]='0';
		}else if(str[len-1]=='o'){
			str[len-1]='1';
		}
		puts(str);
	}
}
