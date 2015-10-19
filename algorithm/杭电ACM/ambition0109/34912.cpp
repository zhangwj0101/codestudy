////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-16 12:43:13
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3491
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:444KB
//////////////////System Comment End//////////////////
/*
 * 3491.cpp
 *
 *  Created on: 2010-12-16
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 205
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int id,flow,next;
	Edge(){}
	Edge(int i,int f,int n):
		id(i),flow(f),next(n){}
}E[999999];
int pre[M],cur[M],gap[M],dis[M];
int head[M],node;

int SAP(int s,int t,int n){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=1;i<=n;i++) cur[i]=head[i];
	int u=pre[s]=s,MFlow=0,mf=INF;
	gap[0]=n;
	while(dis[s]<n){
		loop:for(int &i=cur[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(E[i].flow&&dis[u]==dis[v]+1){
				mf=MIN(mf,E[i].flow);
				pre[v]=u; u=v;
				if(v==t){
					MFlow+=mf;
					for(u=pre[u];v!=s;v=u,u=pre[u]){
						E[cur[u]].flow-=mf;
						E[cur[u]^1].flow+=mf;
					}
					mf=INF;
				}
				goto loop;
			}
		}
		int mdis=n;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(E[i].flow&&mdis>dis[v]){
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
		int n,m,s,t;
		Init();
		scanf("%d%d%d%d",&n,&m,&s,&t);
		for(int i=1;i<=n;i++){
			int cost;
			scanf("%d",&cost);
			Insert(i<<1,i<<1|1,cost);
		}
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			Insert(u<<1|1,v<<1,INF);
			Insert(v<<1|1,u<<1,INF);
		}
		int Ans=SAP(s<<1|1,t<<1,n<<1);
		printf("%d\n",Ans);
	}
}
