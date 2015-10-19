////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-03 12:50:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1569
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:12012KB
//////////////////System Comment End//////////////////
/*
 * 1565.cpp
 *
 *  Created on: 2010-12-3
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 2800
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int lp,cap,next;
	Edge(int _lp=0,int _cap=0,int _next=0):
		lp(_lp),cap(_cap),next(_next){}
}E[999999];
int pre[M],cur[M],gap[M],dis[M];
int head[M],node;

int SAP(int s,int t,int N){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=0;i<N;i++) cur[i]=head[i];
	int u=pre[s]=s, MFlow=0,mf=INF;
	gap[0]=N;
	while(dis[s]<N){
		loop: for(int& i=cur[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].cap&&dis[u]==dis[v]+1){
				mf=MIN(mf,E[i].cap);
				pre[v]=u; u=v;
				if(v==t){
					MFlow+=mf;
					for(u=pre[u];v!=s;v=u,u=pre[u]){
						E[cur[u]].cap-=mf;
						E[cur[u]^1].cap+=mf;
					}
					mf=INF;
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

int Map[25][25];
int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		int Sum=0; Init();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&Map[i][j]);
				Sum+=Map[i][j];
				if((i+j)&1){
					Insert(n*m,i*m+j,Map[i][j]);
					if(i>0) Insert((i*m+j),((i-1)*m+j),INF);
					if(j>0) Insert((i*m+j),(i*m+j-1),INF);
					if(i<n-1) Insert((i*m+j),((i+1)*m+j),INF);
					if(j<m-1) Insert((i*m+j),(i*m+j+1),INF);
				}else{
					Insert(i*m+j,n*m+1,Map[i][j]);
					if(i>0) Insert(((i-1)*m+j),(i*m+j),INF);
					if(j>0) Insert((i*m+j-1),(i*m+j),INF);
					if(i<n-1) Insert(((i+1)*m+j),(i*m+j),INF);
					if(j<m-1) Insert((i*m+j+1),(i*m+j),INF);
				}
			}
		}
		int Ans=SAP(n*m,n*m+1,n*m+2);
		printf("%d\n",Sum-Ans);
	}
}
