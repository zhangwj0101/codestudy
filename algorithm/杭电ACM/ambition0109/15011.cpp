////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-30 16:24:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1501
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:384KB
//////////////////System Comment End//////////////////
/*
 * 1501.cpp
 *
 *  Created on: 2010-10-30
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

char a[205],b[205],str[405];
int dp[205][205];

int dfs(int ia,int ib){
	int it=ia+ib;
	if(ia==int(strlen(a))&&ib==int(strlen(b))){
		return 1;
	}
	if(a[ia]==str[it]&&ia!=int(strlen(a))){
		if(dp[ia+1][ib]==-1){
			dp[ia+1][ib]=dfs(ia+1,ib);
		}
		if(dp[ia+1][ib]) return dp[ia+1][ib];
	}
	if(b[ib]==str[it]&&ib!=int(strlen(b))){
		if(dp[ia][ib+1]==-1){
			dp[ia][ib+1]=dfs(ia,ib+1);
		}
		if(dp[ia][ib+1]) return dp[ia][ib+1];
	}
	return 0;
}

int main(){
	int n,cas=0;
	scanf("%d",&n);
	while(n--){
		scanf("%s %s %s",a,b,str);
		memset(dp,-1,sizeof(dp));
		printf("Data set %d: ",++cas);
		puts(dfs(0,0)?"yes":"no");
	}
}
