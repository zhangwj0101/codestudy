////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-29 20:46:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2728
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:192KB
//////////////////System Comment End//////////////////
/*
 * 2728.cpp
 *
 *  Created on: 2010-9-29
 *      Author: administrator
 */

#include<cstdio>
using namespace std;

int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int main(){
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d),a||b||c||d){
		int vt1=Min(c*100/a,d*100/b);
		if(vt1>100){
			puts("100%");
			continue;
		}
		int vt2=Min(c*100/b,d*100/a);
		if(vt2>100){
			puts("100%");
			continue;
		}
		printf("%d%%\n",Max(vt1,vt2));
	}
}
