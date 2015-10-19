////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-26 16:23:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1011
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*
 * 1011.cpp
 *
 *  Created on: 2010-9-26
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n,m;
int dp[105][105];
vector<vector<int> > Map;
int cost[105],val[105];
bool Hash[105];

int Max(int a,int b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

void Dfs(int t){
	Hash[t]=true;
	int sz=int(Map[t].size());
	dp[t][cost[t]]=val[t];
	for(int i=0;i<sz;i++){
		if(Hash[Map[t][i]]) continue;
		Dfs(Map[t][i]);
		for(int j=m;j>=0;j--){
			for(int k=0;k<=j;k++){
				if(j==m&&k==0) continue;
				if(dp[t][j-k]==-1) continue;
				if(dp[Map[t][i]][k]==-1) continue;
				dp[t][j]=Max(dp[t][j],dp[t][j-k]+dp[Map[t][i]][k]);
			}
		}
	}
	if(cost[t]==0){
		dp[t][1]=Max(dp[t][0],dp[t][1]);
		dp[t][0]=-1;
	}
}


int main(){
	while(scanf("%d%d",&n,&m),n!=-1||m!=-1){
		memset(Hash,false,sizeof(Hash));
		memset(dp,-1,sizeof(dp));
		Map.clear();
		Map.resize(n+1);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&cost[i],&val[i]);
			cost[i]=(cost[i]+19)/20;
			if(cost[i]>100) Hash[i]=true;
		}
		cost[0]=val[0]=0;
		for(int j=0;j<n-1;j++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Map[c1].push_back(c2);
			Map[c2].push_back(c1);
		}
		Dfs(1);

		int Ans=0;
		for(int i=0;i<=m;i++){
			if(dp[1][i]==-1) continue;
			if(Ans<dp[1][i]) Ans=dp[1][i];
		}
		printf("%d\n",Ans);
	}
}
