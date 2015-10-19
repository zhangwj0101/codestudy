////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-04 19:27:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2393
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:160KB
//////////////////System Comment End//////////////////
/*
 * 2393.cpp
 *
 *  Created on: 2010-10-4
 *      Author: administrator
 */

#include<cstdio>
using namespace std;

int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a=a*a; b=b*b; c=c*c;
		printf("Scenario #%d:\n",++cas);
		if(a+b==c||a+c==b||b+c==a){
			puts("yes\n");
		}else{
			puts("no\n");
		}
	}
}
