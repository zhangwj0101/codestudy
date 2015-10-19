////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-26 10:48:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1158
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*
 * 1158.cpp
 *
 *  Created on: 2010-10-26
 *      Author: hduacm
 */

#include<cstdio>
#include<vector>
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

struct Node{
	int cnt,cost;
};

int need[13],mmax[13];
vector<Node> dp[13];
int main(){
	int n;
	while(scanf("%d",&n),n){
		int hire,fire,salsry;
		scanf("%d%d%d",&hire,&salsry,&fire);
		mmax[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&need[i]);
			mmax[i]=Max(mmax[i-1],need[i]);
		}
		for(int i=0;i<13;i++){
			dp[i].clear();
		}
		Node tmp;
		tmp.cnt=0; tmp.cost=0;
		dp[0].push_back(tmp);
		for(int i=1;i<=n;i++){
			for(int j=need[i];j<=mmax[i];j++){
				tmp.cnt=j;
				int sz=dp[i-1].size();
				int min=1000000;
				for(int k=0;k<sz;k++){
					int cost;
					if(dp[i-1][k].cnt>j){
						cost=fire*(dp[i-1][k].cnt-j);
					}else{
						cost=hire*(j-dp[i-1][k].cnt);
					}
					cost+=dp[i-1][k].cost;
					min=Min(cost,min);
				}
				tmp.cost=min+j*salsry;
				dp[i].push_back(tmp);
			}
		}

		int Ans=1000000;
		int sz=dp[n].size();
		for(int i=0;i<sz;i++){
			Ans=Min(dp[n][i].cost,Ans);
		}
		printf("%d\n",Ans);
	}
}
