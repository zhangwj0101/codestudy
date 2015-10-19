////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-14 17:49:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3395
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:396KB
//////////////////System Comment End//////////////////
/*
 * 3395.cpp
 *
 *  Created on: 2010-11-14
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int M=205;

struct Edge{
	int lp,flow,cost,next;
	Edge(){}
	Edge(int _lp,int _flow,int _cost,int _next):
		lp(_lp),flow(_flow),cost(_cost),next(_next){
	}
}E[100000];
queue<int> que;
int pre[M],cost[M],cur[M];
int head[M],node;
bool vis[M];

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int f,int c){
	E[node]=Edge(v,f,c,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,-c,head[v]);
	head[v]=node++;
}

int MCF(int s,int t){
	int MCost=0;
	while(true){
		memset(pre,-1,sizeof(pre));
		memset(vis,false,sizeof(vis));
		memset(cost,0x7f,sizeof(cost));
		cost[s]=0;
		que.push(s);
		while(!que.empty()){
			int u=que.front();
			que.pop();
			vis[u]=false;
			for(int i=head[u];i!=-1;i=E[i].next){
				int v=E[i].lp;
				if(E[i].flow&&cost[u]+E[i].cost<cost[v]){
					cost[v]=cost[u]+E[i].cost;
					if(!vis[v]){
						vis[v]=true;
						que.push(v);
					}
					pre[v]=u;
					cur[v]=i;
				}
			}
		}
		if(pre[t]==-1){
			break;
		}
		for(int v=t;v!=s;v=pre[v]){
			E[cur[v]].flow-=1;
			E[cur[v]^1].flow+=1;
		}
		MCost+=cost[t];
	}
	return MCost;
}

int val[105];
char s[105][105];
int main(){
	int n;
	while(scanf("%d",&n),n){
		Init();
		for(int i=0;i<n;i++){
			scanf("%d",&val[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]=='1'){
					Insert(i,j+n,1,-(val[i]^val[j]));
				}
			}
		}
		for(int i=0;i<n;i++){
			Insert(n*2,i,1,0);
			Insert(i+n,n*2+1,1,0);
			Insert(i,n*2+1,1,0);
		}
		int Ans=MCF(n*2,n*2+1);
		printf("%d\n",-Ans);
	}
}
