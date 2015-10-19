////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-26 11:18:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3549
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:11984KB
//////////////////System Comment End//////////////////
/*
 * 3549.cpp
 *
 *  Created on: 2010-11-26
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

#define M 20
#define INF 0x7fffffff
#define MIN(a,b) (a>b?b:a)
int pre[M], cur[M], gap[M], dis[M];
int head[M], node, N;

struct Edge {
	int lp, cap, next;
	Edge(int _lp=0, int _cap=0, int _next=0) :
		lp(_lp), cap(_cap), next(_next) {
	}
} E[999999];

int SAP(int s, int t) {
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	for (int i = 0; i < N; i++)
		cur[i] = head[i];
	int u = pre[s] = s, MFlow = 0, mf = INF;
	gap[0] = N;
	while (dis[s] < N) {
		loop: for (int &i = cur[u]; i != -1; i = E[i].next) {
			int v = E[i].lp;
			if (E[i].cap && dis[u] == dis[v] + 1) {
				mf = MIN(mf,E[i].cap);
				pre[v] = u;
				u = v;
				if (v == t) {
					MFlow += mf;
					for (u = pre[u]; v != s; v = u, u = pre[u]) {
						E[cur[u]].cap -= mf;
						E[cur[u] ^ 1].cap += mf;
					}
					mf = INF;
				}
				goto loop;
			}
		}
		int mdis = N;
		for (int i = head[u]; i != -1; i = E[i].next) {
			int v = E[i].lp;
			if (E[i].cap && mdis > dis[v]) {
				cur[u] = i;
				mdis = dis[v];
			}
		}
		if ((--gap[dis[u]]) == 0)
			break;
		gap[dis[u] = mdis + 1]++;
		u = pre[u];
	}
	return MFlow;
}

void Insert(int u, int v, int c) {
	E[node] = Edge(v, c, head[u]);
	head[u] = node++;
	E[node] = Edge(u, 0, head[v]);
	head[v] = node++;
}

void Init() {
	memset(head, -1, sizeof(head));
	node = 0;
}
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		Init();
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int u,v,f;
			scanf("%d%d%d",&u,&v,&f);
			Insert(u,v,f);
		}
		N=n;
		int Ans=SAP(1,n);
		printf("Case %d: %d\n",++cas,Ans);
	}
}
