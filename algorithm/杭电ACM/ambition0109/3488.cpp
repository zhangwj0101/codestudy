////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-16 18:55:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3488
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:960KB
//////////////////System Comment End//////////////////
/*
 * 3488.cpp
 *
 *  Created on: 2010-12-16
 *      Author: hduacm
 */

#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=405;

struct Edge{
	int id,flow,cost,next;
	Edge(){}
	Edge(int i,int f,int c,int n):
		id(i),flow(f),cost(c),next(n){}
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

int MCF(int s,int t){
	int MCost=0;
	while(true){
		memset(pre,-1,sizeof(pre));
		memset(vis,false,sizeof(vis));
		memset(cost,0x7f,sizeof(cost));
		cost[s]=0; que.push(s);
		while(!que.empty()){
			int u=que.front(); que.pop();
			vis[u]=false;
			for(int i=head[u];i!=-1;i=E[i].next){
				int v=E[i].id;
				if(E[i].flow&&cost[u]+E[i].cost<cost[v]){
					cost[v]=cost[u]+E[i].cost;
					if(!vis[v]){
						vis[v]=true; que.push(v);
					}
					pre[v]=u; cur[v]=i;
				}
			}
		}
		if(pre[t]==-1) break;
		for(int v=t;v!=s;v=pre[v]){
			E[cur[v]].flow-=1;
			E[cur[v]^1].flow+=1;
		}
		MCost+=cost[t];
	}
	return MCost;
}

int main(){

	int t;
	scanf("%d",&t);
	while(t--){
		Init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int p1,p2,c;
			scanf("%d%d%d",&p1,&p2,&c);
			Insert(p1,p2+n,1,c);
		}
		for(int i=1;i<=n;i++){
			Insert(0,i,1,0);
			Insert(i+n,n*2+1,1,0);
		}
		int Ans=MCF(0,n*2+1);
		printf("%d\n",Ans);
	}
}
