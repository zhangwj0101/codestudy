////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-24 13:02:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1561
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*
 * 1561.cpp
 *
 *  Created on: 2010-9-24
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> Map[210];
int Dp[210][210];
int Val[210];
int n,m;

int Max(int a,int b){
	int dif=(b-a);
	return b-(dif&(dif>>31));
}

void Dfs(int t){
	int size=int(Map[t].size());
	if(t) Dp[t][1]=Val[t];
	for(int i=0;i<size;i++){
		Dfs(Map[t][i]);
		for(int k=m;k>=0;k--){
			for(int j=1;j<=k;j++){
				if(Dp[Map[t][i]][j]==-1) continue;
				if(Dp[t][k-j]==-1) continue;
				Dp[t][k]=Max(Dp[t][k],Dp[t][k-j]+Dp[Map[t][i]][j]);
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&n,&m),n||m){

		memset(Dp,-1,sizeof(Dp));
		for(int i=0;i<=n;i++){
			Map[i].clear();
		}
		for(int i=1;i<=n;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Map[c1].push_back(i);
			Val[i]=c2;
		}
		Dp[0][0]=0;
		Dfs(0);
		printf("%d\n",Dp[0][m]);
	}
}
