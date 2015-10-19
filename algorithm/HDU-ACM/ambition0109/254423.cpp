////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-08 16:25:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
/*
 * 3169.cpp
 *
 *  Created on: 2010-12-8
 *      Author: hduacm
 */

#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define M 105

struct Edge{
	int id,val,next;
	Edge(){}
	Edge(int i,int v,int n):
		id(i),val(v),next(n){}
}E[999999];
int head[M],node;
int cost[M],cnt[M];
bool vis[M];

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int c){
	E[node]=Edge(v,c,head[u]);
	head[u]=node++;
	E[node]=Edge(u,c,head[v]);
	head[v]=node++;
}

bool SPFA(int s,int n){
	memset(cost,-1,sizeof(cost));
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	cost[s]=0;
	queue<int> QUE;
	QUE.push(s);
	while(!QUE.empty()){
		int u=QUE.front(); QUE.pop();
		vis[u]=false;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(cost[v]==-1||E[i].val+cost[u]<cost[v]){
				cost[v]=E[i].val+cost[u];
				if((++cnt[v])>n) return false;
				if(!vis[v]){
					QUE.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return true;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		Init();
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Insert(c1,c2,cost);
		}
		SPFA(1,n);
		printf("%d\n",cost[n]);
	}
}
