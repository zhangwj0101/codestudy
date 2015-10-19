////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-09 21:54:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1269
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2084KB
//////////////////System Comment End//////////////////
/*
 * Kosaraju.cpp
 *
 *  Created on: 2010-12-9
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 10005
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int id,next;
}G1[100005],G2[100005];
int h1[M],h2[M],n1,n2;
int order[M],id[M],scc,cnt;
bool vis[M];

void Init(){
	memset(h1,-1,sizeof(h1));
	memset(h2,-1,sizeof(h2));
	n1=n2=0;
}

void Insert(int u,int v){
	G1[n1].id=v; G1[n1].next=h1[u];
	h1[u]=n1++;
	G2[n2].id=u; G2[n2].next=h2[v];
	h2[v]=n2++;
}

void dfs1(int u){
	vis[u]=true;
	for(int v=h1[u];v!=-1;v=G1[v].next){
		if(!vis[G1[v].id]){
			dfs1(G1[v].id);
		}
	}
	order[cnt++]=u;
}

void dfs2(int u){
	vis[u]=true;
	id[u]=scc;
	for(int v=h2[u];v!=-1;v=G2[v].next){
		if(!vis[G2[v].id]){
			dfs2(G2[v].id);
		}
	}
}

int Kosaraju(int n){
	scc=cnt=1;
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	memset(vis,false,sizeof(vis));
	for(int i=n;i>0;i--){
		if(!vis[order[i]]){
			dfs2(order[i]);
			scc++;
		}
	}
	return scc-1;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		Init();
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			Insert(u,v);
		}
		//printf("%d\n",Kosaraju(n));
		puts(Kosaraju(n)==1?"Yes":"No");
	}
}
