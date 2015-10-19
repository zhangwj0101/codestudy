////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-20 19:48:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1976
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 1976.cpp
 *
 *  Created on: 2010-10-20
 *      Author: administrator
 */

#include<cstdio>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a[2],b[2],c[2];
		scanf("%d%d%d",&a[0],&b[0],&c[0]);
		scanf("%d%d%d",&a[1],&b[1],&c[1]);
		if(a[0]>a[1]) puts("First");
		else if(a[1]>a[0]) puts("Second");
		else{
			if(b[0]>b[1]) puts("First");
			else if(b[1]>b[0]) puts("Second");
			else{
				if(c[0]>c[1]) puts("First");
				else if(c[1]>c[0]) puts("Second");
				else puts("Same");
			}
		}
	}
}
