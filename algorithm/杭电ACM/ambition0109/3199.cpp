////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-30 20:10:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3199
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*
 * 3199.cpp
 *
 *  Created on: 2010-8-30
 *      Author: ambition
 */

#include<cstdio>
using namespace std;

long long Min(long long a,long long b,long long c){
	long long min=a;
	if(min>b) min=b;
	if(min>c) min=c;
	return min;
}

long long dp[10000];
int main()
{
	long long p1,p2,p3,n;
	while(scanf("%I64d%I64d%I64d%I64d",&p1,&p2,&p3,&n)!=EOF){
		dp[0]=1;
		int v1=0,v2=0,v3=0;
		for(int i=1;i<=n;i++){
			do{
				dp[i]=Min(dp[v1]*p1,dp[v2]*p2,dp[v3]*p3);
				if(dp[i]==dp[v1]*p1) v1++;
				else if(dp[i]==dp[v2]*p2) v2++;
				else if(dp[i]==dp[v3]*p3) v3++;
			}while(dp[i]==dp[i-1]);
		}
		printf("%I64d\n",dp[n]);
	}
}
