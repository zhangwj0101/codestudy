////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-12 20:38:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3376
////Problem Title: 
////Run result: Accept
////Run time:1671MS
////Run memory:48480KB
//////////////////System Comment End//////////////////
/*
 * 3376.cpp
 *
 *  Created on: 2010-11-12
 *      Author: amb
 */

#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct Edge{
	int lc,f,v,next;
	Edge(){}
	Edge(int _lc,int _f,int _v,int _next):
	lc(_lc),f(_f),v(_v),next(_next){}
}E[10000000];

int pre[800000],val[800000],cur[800000];
int head[800000],node;
bool vis[800000];
int MCF(int s,int t){
	int MCost=0;
	while(true){
		memset(pre,-1,sizeof(pre));
		memset(vis,false,sizeof(vis));
		memset(val,0x7f,sizeof(val));
		val[s]=0;
		queue<int> que;
		que.push(s);
		while(!que.empty()){
			int u=que.front();
			que.pop();
			vis[u]=false;
			//printf("# %d %d\n",u,val[u]);
			for(int i=head[u];i!=-1;i=E[i].next){
				int v=E[i].lc;
				if(E[i].f&&val[u]+E[i].v<val[v]){
					val[v]=val[u]+E[i].v;
					if(!vis[v]){
						vis[v]=true;
						que.push(v);
					}
					pre[v]=u; cur[v]=i;
				}
			//	puts("$4");
			}
		//	puts("$3");
		}
		if(pre[t]==-1) break;
		int mf=0x7fffffff;
		for(int v=t;v!=s;v=pre[v]){
			if(mf>E[cur[v]].f){
				mf=E[cur[v]].f;
			}
			//puts("$1");
			//printf("== %d\n",v);
		}
		for(int v=t;v!=s;v=pre[v]){
			E[cur[v]].f-=mf;
			E[cur[v]^1].f+=mf;
			//puts("$2");
		}
		MCost+=val[t];

	}
	return MCost;
}

void Insert(int s,int t,int f,int v){
	E[node]=Edge(t,f,v,head[s]);
	head[s]=node++;
	E[node]=Edge(s,0,-v,head[t]);
	head[t]=node++;
}

int map[605][605];
int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(head,-1,sizeof(head));
		node=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&map[i][j]);
			}
		}
		//puts("*");
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if((i==0&&j==0)||(i==n-1&&j==n-1)){
					Insert((i*n+j)<<1,((i*n+j)<<1)|1,2,0);
				}else{
					Insert((i*n+j)<<1,((i*n+j)<<1)|1,1,-map[i][j]);
				}
				if(i+1<n){
					Insert(((i*n+j)<<1)|1,((i+1)*n+j)<<1,1,0);
				}
				if(j+1<n){
					Insert(((i*n+j)<<1)|1,(i*n+j+1)<<1,1,0);
				}
			}
		}
		//puts("*");
		int Ans=MCF(0,(n*n-1)<<1|1);
		//puts("*");
		printf("%d\n",-Ans+map[n-1][n-1]+map[0][0]);
	}
}
