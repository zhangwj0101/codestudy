////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-09 20:25:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1269
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1420KB
//////////////////System Comment End//////////////////
/*
 * Tarjan.cpp
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
}E[999999];
int dep[M],low[M],blg[M],step,scc;
int head[M],node;
int stk[M],top;
bool ins[M];

void Init(){
	memset(head,-1,sizeof(head));
	memset(dep,-1,sizeof(dep));
	memset(ins,false,sizeof(ins));
	node=step=scc=0; top=-1;
}

void Insert(int u,int v){
	E[node].id=v;
	E[node].next=head[u];
	head[u]=node++;
}

void Tarjan(int u){
	stk[++top]=u; ins[u]=true;
	dep[u]=low[u]=step++;
	for(int i=head[u];i!=-1;i=E[i].next){
		int v=E[i].id;
		if(dep[v]==-1){
			Tarjan(v);
			low[u]=MIN(low[u],low[v]);
		}else if(ins[v]){
			low[u]=MIN(low[u],dep[v]);
		}
	}
	if(low[u]==dep[u]){
		for(int v;v!=u;top--){
			v=stk[top];
			ins[v]=false;
			blg[v]=scc;
		}
		scc++;
	}
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
		for(int i=1;i<=n;i++){
			if(dep[i]==-1){
				Tarjan(i);
			}
		}
		puts((scc==1)?"Yes":"No");
	}
}


