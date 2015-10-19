////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-28 19:04:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2448
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:31880KB
//////////////////System Comment End//////////////////
/*
 * 2448.cpp
 *
 *  Created on: 2010-11-28
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 310
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int lc,flow,cost,next;
	Edge(int _lc=0,int _flow=0,int _cost=0,int _next=0):
		lc(_lc),flow(_flow),cost(_cost),next(_next){}
}E[2][999999];
int path[M][M],pre[M],cur[M];
int h[2][M],nn,nm;
bool vis[M];

void SPFA(int s,bool mcf){
	memset(path[s],-1,sizeof(path[s]));
	memset(vis,false,sizeof(vis));
	memset(pre,-1,sizeof(pre));
	path[s][s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for(int i=h[mcf][u];i!=-1;i=E[mcf][i].next){
			int v=E[mcf][i].lc;
			if(E[mcf][i].flow&&(E[mcf][i].cost+path[s][u]<path[s][v]||path[s][v]==-1)){
				path[s][v]=path[s][u]+E[mcf][i].cost;
				pre[v]=u; cur[v]=i;
				if(!vis[v]){
					que.push(v);
					vis[v]=true;
				}
			}
		}
	}
}

int MCF(int s,int t){
	int MCost=0;
	while(true){
		SPFA(s,true);
		if(pre[t]==-1) break;
		int mf=INF;
		for(int v=t;v!=s;v=pre[v]){
			mf=MIN(mf,E[1][cur[v]].flow);
		}
		for(int v=t;v!=s;v=pre[v]){
			E[1][cur[v]].flow-=mf;
			E[1][cur[v]^1].flow+=mf;
		}
		MCost+=path[s][t];
	}
	return MCost;
}

void Insn(int u,int v,int c,int f=1){
	E[0][nn]=Edge(v,f,c,h[0][u]);
	h[0][u]=nn++;
	E[0][nn]=Edge(u,f,c,h[0][v]);
	h[0][v]=nn++;
}

void Insm(int u,int v,int c,int f){
	E[1][nm]=Edge(v,f,c,h[1][u]);
	h[1][u]=nm++;
	E[1][nm]=Edge(u,0,-c,h[1][v]);
	h[1][v]=nm++;
}

void Init(){
	memset(h,-1,sizeof(h));
	nn=nm=0;
}

int ship[105];
int mmin[105][105];
int main(){
	int n,m,k,p;
	while(~scanf("%d%d%d%d",&n,&m,&k,&p)){
		Init();
		memset(mmin,0x7f,sizeof(mmin));
		for(int i=0;i<n;i++){
			scanf("%d",&ship[i]);
			Insm(0,ship[i],0,1);
			Insm(i+1+m,n+m+1,0,1);
		}
		for(int i=0;i<k;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Insn(c1,c2,cost);
		}
		for(int i=0;i<n;i++){
			SPFA(ship[i],false);
		}
		for(int i=0;i<p;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			for(int j=0;j<n;j++){
				if(path[ship[j]][c2]!=-1)
				mmin[j][c1]=MIN(mmin[j][c1],path[ship[j]][c2]+cost);
			}
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<=n;j++){
				if(mmin[i][j]!=0x7f7f7f7f){
					Insm(ship[i],j+m,mmin[i][j],1);
				}
			}
		}
		int Ans=MCF(0,n+m+1);
		printf("%d\n",Ans);
	}
}
