////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-13 18:39:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1853
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:536KB
//////////////////System Comment End//////////////////
/*
 * 1853.cpp
 *
 *  Created on: 2010-11-13
 *      Author: amb
 */

#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=205;

struct Edge{
	int lp,flow,cost,next;
	Edge(){}
	Edge(int _lp,int _flow,int _cost,int _next):
	lp(_lp),flow(_flow),cost(_cost),next(_next){}
}E[999999];
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

int MCF(int s,int t,int need){
	int MCost=0,MFlow=0;
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
					pre[v]=u; cur[v]=i;
				}
			}
		}
		if(pre[t]==-1) break;
//		int mf=1000000;
//		for(int v=t;v!=s;v=pre[v]){
//			if(mf>E[cur[v]].flow){
//				mf=E[cur[v]].flow;
//			}
//		}
		for(int v=t;v!=s;v=pre[v]){
			E[cur[v]].flow-=1;
			E[cur[v]^1].flow+=1;
		}
		MCost+=cost[t];
		MFlow+=1;
	}
	if(MFlow!=need) return -1;
	return MCost;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		Init();
		for(int i=0;i<m;i++){
			int p1,p2,c;
			scanf("%d%d%d",&p1,&p2,&c);
			Insert(p1,p2+n,1,c);
		}
		for(int i=1;i<=n;i++){
			Insert(0,i,1,0);
			Insert(i+n,n*2+1,1,0);
		}
		int Ans=MCF(0,n*2+1,n);
		printf("%d\n",Ans);
	}
}
