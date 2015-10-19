////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-27 19:35:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3046
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:12556KB
//////////////////System Comment End//////////////////
/*
 * 3046.cpp
 *
 *  Created on: 2010-11-27
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 40010
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int lp,cap,next;
	Edge(int _lp=0,int _cap=0,int _next=0):
		lp(_lp),cap(_cap),next(_next){}
}E[999999];
int pre[M],cur[M],gap[M],dis[M];
int head[M],node,N;

int SAP(int s,int t){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=0;i<N;i++){
		cur[i]=head[i];
	}
	int u=pre[s]=s,MFlow=0,mf=INF;
	gap[0]=N;
	while(dis[s]<N){
		loop: for(int& i=cur[u];i!=-1;i=E[i].next){
			int v=E[i].lp;
			if(E[i].cap&&dis[u]==dis[v]+1){
				mf=MIN(mf,E[i].cap);
				pre[v]=u;
				u=v;
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

void Init(int n,int m){
	memset(head,-1,sizeof(head));
	node=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+1<n){
				Insert(i*m+j,(i+1)*m+j,1);
				Insert((i+1)*m+j,i*m+j,1);
			}
			if(j+1<m){
				Insert(i*m+j,i*m+j+1,1);
				Insert(i*m+j+1,i*m+j,1);
			}
		}
	}
}

int main(){
	int n,m,cas=0;
	while(~scanf("%d%d",&n,&m)){
		Init(n,m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp==1){
					Insert(n*m,i*m+j,INF);
				}else if(tmp==2){
					Insert(i*m+j,n*m+1,INF);
				}
			}
		}
		N=n*m+2;
		int Ans=SAP(n*m,n*m+1);
		printf("Case %d:\n%d\n",++cas,Ans);
	}
}
