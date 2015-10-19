////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-24 16:24:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3277
////Problem Title: 
////Run result: Accept
////Run time:1031MS
////Run memory:1324KB
//////////////////System Comment End//////////////////
/*
 * 3277.cpp
 *
 *  Created on: 2010-11-24
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 1000
#define INF 0x7fffffff
#define MIN(a,b) (a>b?b:a)
int pre[M],cur[M],gap[M],dis[M];
int head[M],node,N;
bool map[300][300];

struct Edge{
	int lp,cap,next;
	Edge(){}
	Edge(int _lp,int _cap,int _next):
		lp(_lp),cap(_cap),next(_next){}
}E[999999];

int SAP(int s,int t){
	memset(dis,0,sizeof(dis));
	memset(gap,0,sizeof(gap));
	for(int i=0;i<N;i++){
		cur[i]=head[i];
	}
	int u=pre[s]=s,MFlow=0,mf=INF;
	gap[0]=N;
	while(dis[s]<N){
		loop: for(int &i=cur[u];i!=-1;i=E[i].next){
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
		if((--gap[dis[u]])==0){
			break;
		}
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

int idx[300];
inline int Find(int t){
	if(idx[t]==-1) return t;
	return idx[t]=Find(idx[t]);
}

bool Merge(int a,int b){
	int ra=Find(a);
	int rb=Find(b);
	if(ra==rb) return false;
	idx[rb]=ra;
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k,f;
		scanf("%d%d%d%d",&n,&m,&k,&f);

		memset(map,false,sizeof(map));
		for(int i=0;i<m;i++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			map[t1][t2]=true;
		}
		memset(idx,-1,sizeof(idx));
		for(int i=0;i<f;i++){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			Merge(t1,t2);
		}
		for(int i=1;i<=n;i++){
			int r=Find(i);
			if(r==i) continue;
			for(int j=1;j<=n;j++){
				map[r][j]|=map[i][j];
			}
		}
		N=3*n+2;
		int top=0,bot=n;
		int mid=(top+bot)>>1,ans=mid;
		while(top<=bot){
			Init();
			for(int i=1;i<=n;i++){
				Insert(0,i,mid);
				Insert(i,i+n,k);
				Insert(i+2*n,3*n+1,mid);
				int r=Find(i);
				for(int j=1;j<=n;j++){
					if(map[r][j]){
						Insert(i,j+2*n,1);
					}else{
						Insert(i+n,j+2*n,1);
					}
				}
			}
			int mf=SAP(0,3*n+1);
			if(mf==mid*n){
				top=(ans=mid)+1;
			}else{
				bot=mid-1;
			}
			mid=(top+bot)>>1;
		}
		printf("%d\n",ans);
	}
}
