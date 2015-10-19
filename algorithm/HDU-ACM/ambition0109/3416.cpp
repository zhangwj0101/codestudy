////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-17 15:50:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3416
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:6304KB
//////////////////System Comment End//////////////////
/*
 * 3416g.cpp
 *
 *  Created on: 2010-11-17
 *      Author: hduacm
 */

#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N=1005;

struct City{
	int lp,cost;
	void set(int _lp,int _cost){
		lp=_lp; cost=_cost;
	}
};
vector<City> GraA[N],GraB[N];
int PathA[N],PathB[N];
bool Hash[N];

void SPFAA(int s){
	memset(PathA,-1,sizeof(PathA));
	memset(Hash,false,sizeof(Hash));
	PathA[s]=0;
	queue<int> Que;
	Que.push(s);
	while(!Que.empty()){
		int u=Que.front();
		Que.pop();
		Hash[u]=false;
		for(unsigned i=0;i<GraA[u].size();i++){
			int v=GraA[u][i].lp;
			if(GraA[u][i].cost+PathA[u]<PathA[v]||PathA[v]==-1){
				PathA[v]=GraA[u][i].cost+PathA[u];
				if(!Hash[v]){
					Que.push(v);
					Hash[v]=true;
				}
			}
		}
	}
}

void SPFAB(int s){
	memset(PathB,-1,sizeof(PathB));
	memset(Hash,false,sizeof(Hash));
	PathB[s]=0;
	queue<int> Que;
	Que.push(s);
	while(!Que.empty()){
		int u=Que.front();
		Que.pop();
		Hash[u]=false;
		for(unsigned i=0;i<GraB[u].size();i++){
			int v=GraB[u][i].lp;
			if(GraB[u][i].cost+PathB[u]<PathB[v]||PathB[v]==-1){
				PathB[v]=GraB[u][i].cost+PathB[u];
				if(!Hash[v]){
					Que.push(v);
					Hash[v]=true;
				}
			}
		}
	}
}

struct Edge{
	int lp,flow,next;
	Edge(){};
	Edge(int _lp,int _flow,int _next):
		lp(_lp),flow(_flow),next(_next){}
}E[9999999];
int pre[N],dis[N],cur[N],gap[N];
int head[N],node,n,m;

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int f){
	E[node]=Edge(v,f,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,head[v]);
	head[v]=node++;
}

int SAP(int s,int t){
	for(int i=1;i<=n;i++){
		cur[i]=head[i];
	}
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	int u=pre[s]=s,MFlow=0,mf=0x7fffffff;
	gap[0]=n;
	while(dis[s]<n){
		loop:
		for(int &i=cur[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].flow&&dis[u]==dis[v]+1){
				if(E[i].flow<mf) mf=E[i].flow;
				pre[v]=u;
				u=v;
				if(v==t){
					MFlow+=mf;
					for(u=pre[u];v!=s;v=u,u=pre[u]){
						E[cur[u]].flow-=mf;
						E[cur[u]^1].flow+=mf;
					}
					mf=0x7fffffff;
				}
				goto loop;
			}
		}
		int md=n;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].flow&&md>dis[v]){
				cur[u]=i;
				md=dis[v];
			}
		}
		if((--gap[dis[u]])==0) break;
		gap[dis[u]=md+1] ++;
		u=pre[u];
	}
	return MFlow;
}

int tu[N*100],tv[N*100],tc[N*100];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		City tmp;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			GraA[i].clear();
			GraB[i].clear();
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&tu[i],&tv[i],&tc[i]);
			tmp.set(tv[i],tc[i]);
			GraA[tu[i]].push_back(tmp);
			tmp.set(tu[i],tc[i]);
			GraB[tv[i]].push_back(tmp);
		}
		int S,T;
		scanf("%d%d",&S,&T);
		SPFAA(S);
		SPFAB(T);
		int mdis=PathA[T];

		Init();
		for(int i=0;i<m;i++){
			if(PathA[tu[i]]+PathB[tv[i]]==mdis-tc[i]){
				Insert(tu[i],tv[i],1);
			}
		}
		int Ans=SAP(S,T);
		printf("%d\n",Ans);
	}
}
