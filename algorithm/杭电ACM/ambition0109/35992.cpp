////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-16 17:47:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3599
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:6284KB
//////////////////System Comment End//////////////////
/*
 * 3599.cpp
 *
 *  Created on: 2010-12-16
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 1505
#define INF 0x7fffffff

inline void in(int &num)
{
	char in;
	in=getchar();
	while(in<'0'||in>'9'){
		in=getchar();
	}
	num=in-'0';
	in=getchar();
	while(in>='0'&&in<='9'){
		num*=10;num+=in-'0';
		in=getchar();
	}
}


struct Edge {
	int id, flow, cost, next;
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

void Insert(int u, int v, int f, int c) {
	E[node]=Edge(v,f,c,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,-c,head[v]);
	head[v]=node++;
}

int SPFA(int s,int t){
	memset(pre,-1,sizeof(pre));
	memset(vis,false,sizeof(vis));
	memset(cost,0x7f,sizeof(cost));
	cost[s]=0;
	que.push(s);
	while(!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for (int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(E[i].flow &&cost[u]+E[i].cost<cost[v]) {
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
	if(pre[t]==-1) return -1;
	for(int v=t;v!=s;v=pre[v]){
		E[cur[v]].flow-=1;
		E[cur[v]^1].flow+=1;
	}
	return cost[t];
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int u,v,c; Init();
		while(in(u),in(v),in(c),u||v||c){
			Insert(u,v,1,c);
			Insert(v,u,1,c);
		}
		int MCost=SPFA(1,n);
		if(MCost==-1){
			puts("0");
		}else{
			int cnt=1;
			while(SPFA(1,n)==MCost)	cnt++;
			printf("%d\n",cnt);
		}
	}
}
