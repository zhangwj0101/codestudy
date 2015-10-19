////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-20 19:41:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1977
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:16604KB
//////////////////System Comment End//////////////////
/*
 * 1977.cpp
 *
 *  Created on: 2010-8-20
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

long long third[2100001];;
int main()
{
	for(int i=1;i<2100000;i++){
		third[i]=(long long)i*(long long)i*(long long)i;
	}
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%I64d %I64d\n",third[n],third[n+1]);
	}
}
