////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-01 18:56:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3313
////Problem Title: 
////Run result: Accept
////Run time:1312MS
////Run memory:8784KB
//////////////////System Comment End//////////////////
/*
 * 3313.cpp
 *
 *  Created on: 2010-11-23
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define NV 200010
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)
#define clr(a,b) (memset(a,b,sizeof(a)))

struct MF {
	int pre[NV], head[NV],cur[NV];
	int q[NV], front, rear,e;
	struct edge {
		int c, v, next;
		edge(){}
		edge(int _c,int _v,int _next) :
			c(_c),v(_v),next(_next){}
	} E[999999];
	inline void init() {
		e = 0;
		clr(head, -1);
	}
	inline int EK(int s, int t) {
		int i,u,v,maxflow = 0;
		while (true) {
			clr(pre, -1);
			q[front = rear = 0] = s;
			while (front <= rear) {
				u = q[front ++];
				for (i = head[u]; i != -1; i = E[i].next) {
					v = E[i].v;
					if (pre[v] == -1 && E[i].c) {
						pre[v] = u;
						q[++ rear] = v;
						cur[v] = i;
					}
				}
				if (pre[t] != -1) break;
			}
			if (pre[t] == -1) break;
			int mi = INF;
			for (v = t; v != s; v = pre[v]) {
				mi = MIN(mi, E[ cur[v] ].c);
			}
			for (v = t; v != s; v = pre[v]) {
				E[ cur[v] ].c -= mi;
				E[ cur[v]^1 ].c += mi;
			}
			maxflow += mi;
		}
		return maxflow;
	}
	void insert(int u, int v, int c, int cc = 0) {
		E[e] = edge(c,v,head[u]);
		head[u] = e ++;
		E[e] = edge(cc,u,head[v]);
		head[v] = e ++;
	}
} G;


bool vis[NV];int tag;
int que[999999];
int Bfs(int s){
	int *ss,*ee=ss=que;
	*ee++=s;
	vis[s]=false;
	tag=0;
	while(ss<ee){
		int u=*(ss++);
		//printf("= %d\n",u);
		for(int i=G.head[u];i!=-1;i=G.E[i].next){
			int v=G.E[i].v;
			//printf("== %d %d\n",v,tag);
			if(G.E[i].c&&vis[v]){
				*ee++=v; tag^=(v>>1);
				vis[v]=false;
			}
		}
	}
	return tag;
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		G.init();
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			G.insert((u+1)<<1|1,(v+1)<<1,2);
		}
		int s,t;
		scanf("%d%d",&s,&t);
		s++;t++;
		for(int i=1;i<=n;i++){
			if(i==s||i==t){
				G.insert(i<<1,i<<1|1,2);
			}else{
				G.insert(i<<1,i<<1|1,1);
			}
		}
		int MF=G.EK(s<<1,t<<1|1),Ans;
		if(MF==2){
			Ans=2;
		}else if(MF==0){
			Ans=n;
		}else if(MF==1){
			memset(vis,true,sizeof(vis));
			vis[s<<1]=false;
			int cnt=1;
			tag=s;
			while(true){
				cnt++;
				tag=Bfs(tag<<1|1);
				if(tag==0) break;
			}
			Ans=cnt;
		}
		printf("%d\n",Ans);
	}
}
