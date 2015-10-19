////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-23 12:38:23
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1078
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:296KB
//////////////////System Comment End//////////////////
/*
 * 1078.cpp
 *
 *  Created on: 2010-10-23
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;

int Max(const int& a,const int& b){
	int dif=b-a;
	return b-(dif&(dif>>31));
}

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}


int n,m;
int dp[105][105];
int Maze[105][105];
int Dfs(int x,int y){
	int t=Maze[x][y];
	int s=Max(x-m,0);
	int e=Min(x+m,n-1);
	int max=0;
	for(int i=s;i<=e;i++){
		if(Maze[i][y]>t){
			if(dp[i][y]==-1){
				dp[i][y]=Dfs(i,y);
			}
			max=Max(dp[i][y],max);
		}
	}
	s=Max(y-m,0);
	e=Min(y+m,n-1);
	for(int i=s;i<=e;i++){
		if(Maze[x][i]>t){
			if(dp[x][i]==-1){
				dp[x][i]=Dfs(x,i);
			}
			max=Max(dp[x][i],max);
		}
	}
	return max+t;
}

int main(){

	while(scanf("%d%d",&n,&m),n!=-1||m!=-1){
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&Maze[i][j]);
			}
		}
		dp[0][0]=Dfs(0,0);
		printf("%d\n",dp[0][0]);
	}
}
