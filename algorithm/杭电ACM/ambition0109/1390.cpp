////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 15:29:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1390
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*
 * 1390.cpp
 *
 *  Created on: 2010-11-19
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

void CntBit(int num){
	bool f=false;
	for(int i=0;num;i++){
		if(num&1){
			if(f) printf(" ");
			f=true;
			printf("%d",i);
		}
		num>>=1;
	}
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		CntBit(n);
		puts("");
	}
}
