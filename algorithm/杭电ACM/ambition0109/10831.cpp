////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-27 11:54:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:8440KB
//////////////////System Comment End//////////////////
/*
 * 1083.cpp
 *
 *  Created on: 2010-11-27
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 450
#define INF 0x7fffffff
#define MIN(a,b) (a>b?b:a)

struct Edge{
	int lp,cap,next;
	Edge(int _lp=0,int _cap=0,int _next=0):
		lp(_lp),cap(_cap),next(_next){}
}E[699999];
int pre[M],cur[M],gap[M],dis[M];
int head[M],node,N;

int SAP(int s,int t){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=0;i<N;i++) cur[i]=head[i];
	int u=pre[s]=s,MFlow=0;
	gap[0]=N;
	while(dis[s]<N){
		loop: for(int& i=cur[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].cap&&dis[u]==dis[v]+1){
				pre[v]=u;
				u=v;
				if(v==t){
					MFlow+=1;
					for(u=pre[u];v!=s;v=u,u=pre[u]){
						E[cur[u]].cap-=1;
						E[cur[u]^1].cap+=1;
					}
				}
				goto loop;
			}
		}
		int mdis=N;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].cap&&mdis>dis[v]){
				cur[u]=i;
				mdis=dis[v];
			}
		}
		if((--gap[dis[u]])==0) break;
		gap[dis[u]=mdis+1]++;
		u=pre[u];
	}
	return MFlow;
}

void Insert(int u,int v,int c){
	E[node]=Edge(v,c,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,head[v]);
	head[v]=node++;
}

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		Init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			Insert(0,i,1);
			int u; scanf("%d",&u);
			for(int j=0;j<u;j++){
				int v; scanf("%d",&v);
				Insert(i,v+n,1);
			}
		}
		for(int j=1;j<=m;j++){
			Insert(j+n,n+m+1,1);
		}
		N=n+m+2;
		puts(n==SAP(0,n+m+1)?"YES":"NO");
	}
}
