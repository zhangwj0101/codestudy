////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 19:10:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2816
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
/*
 * 2816.cpp
 *
 *  Created on: 2010-9-29
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

//QWERTYUIOPASDFGHJKLZXCVBNM
//ABCDEFGHIJKLMNOPQRSTUVWXYZ
char pcode[][5]={"KXV","MCN","OPH","QRS","ZYI","JADL","EGW","BUFT"};

int main()
{
	char str[1010],turn[510];
	while(gets(str)){
		int len=int(strlen(str));
		for(int i=0;i<len;i+=2){
			turn[i>>1]=pcode[str[i]-'2'][str[i+1]-'1'];
		}
		if((len>>1)&1){
			putchar(turn[len>>2]);
		}
		for(int i=0;i<(len>>2);i++){
			putchar(turn[(len>>1)-i-1]);
			putchar(turn[(len>>2)-i-1]);
		}
		puts("");
	}
}


