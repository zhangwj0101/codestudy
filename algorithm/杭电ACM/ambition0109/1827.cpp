////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-10 12:20:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1827
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*
 * 1827.cpp
 *
 *  Created on: 2010-12-10
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 1005
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int id,next;
}E[3000];
int dep[M],low[M],blg[M],step,scc;
int head[M],node;
int stk[M],top;
bool ins[M];

void Init(){
	memset(head,-1,sizeof(head));
	memset(dep,-1,sizeof(dep));
	memset(ins,false,sizeof(ins));
	node=step=scc=top=0;
}

void Insert(int u,int v){
	E[node].id=v;
	E[node].next=head[u];
	head[u]=node++;
}

void Tarjan(int u){
	stk[top++]=u; ins[u]=true;
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
		for(int v;v!=u;){
			v=stk[--top];
			ins[v]=false;
			blg[v]=scc;
		}
		scc++;
	}
}

int cost[M],deg[M],mmin[M];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			scanf("%d",&cost[i]);
		}
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
//                for(int u=1;u<=n;u++){
//                    printf("%d ",blg[u]);
//                }
//                puts("");

		memset(deg,0,sizeof(deg));
		memset(mmin,0x7f,sizeof(mmin));
		for(int u=1;u<=n;u++){
			mmin[blg[u]]=MIN(cost[u],mmin[blg[u]]);
			for(int i=head[u];i!=-1;i=E[i].next){
				if(blg[u]!=blg[E[i].id]){
					deg[blg[E[i].id]]++;
				}
			}
		}
		int sum=0,cnt=0;
		for(int i=0;i<scc;i++){
			if(deg[i]==0){
				sum+=mmin[i];
				cnt++;
			}
		}
		printf("%d %d\n",cnt,sum);
	}
}
