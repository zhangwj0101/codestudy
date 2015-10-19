////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 14:22:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1260
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*
 * 1260.cpp
 *
 *  Created on: 2010-11-19
 *      Author: hduacm
 */

#include<cstdio>
using namespace std;

int Min(const int& a,const int & b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int time[2005],tog[2005];
int dp[2005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&time[i]);
		}
		for(int i=1;i<n;i++){
			scanf("%d",&tog[i]);
		}
		dp[0]=0; dp[1]=time[1];
		for(int i=2;i<=n;i++){
			dp[i]=Min(dp[i-1]+time[i],dp[i-2]+tog[i-1]);
		}
		int h=8,m=0,s=dp[n];
		char t[5]="am";
		if(s>=60){ m=s/60; s%=60; }
		if(m>=60){ h+=m/60; m%=60; }
		if(h>12){ h-=12; t[0]='p'; }
		printf("%02d:%02d:%02d %s\n",h,m,s,t);
	}
}
