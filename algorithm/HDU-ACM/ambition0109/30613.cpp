////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-05 13:44:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3061
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:1600KB
//////////////////System Comment End//////////////////
/*
 * 3061.cpp
 *
 *  Created on: 2010-12-5
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 550
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge {
	int lp, cap, next;
} E[200000];
int pre[M], cur[M], gap[M], dis[M];
int head[M], node;

int SAP(int s, int t, int N) {
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	for (int i = 0; i < N; i++) cur[i] = head[i];
	int u = pre[s] = s, MFlow = 0, mf = INF;
	gap[0] = N;
	while (dis[s] < N) {
		loop: for (int &i = cur[u]; i != -1; i = E[i].next) {
			int v = E[i].lp;
			if (E[i].cap && dis[u] == dis[v] + 1) {
				mf = MIN(mf,E[i].cap);
				pre[v] = u; u = v;
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
		if ((--gap[dis[u]]) == 0) break;
		gap[dis[u] = mdis + 1]++;
		u = pre[u];
	}
	return MFlow;
}

void Insert(int u, int v, int c) {
	E[node].lp=v; E[node].cap=c; E[node].next=head[u];
	head[u] = node++;
	E[node].lp=u; E[node].cap=0; E[node].next=head[v];
	head[v] = node++;
}

void Init() {
	memset(head, -1, sizeof(head));
	node = 0;
}

int main(){
	int m,n,Sum;
	while(~scanf("%d%d",&n,&m)){
		Init(); Sum=0;
		for(int i=1;i<=n;i++){
			int c;
			scanf("%d",&c);
			if(c>=0){
				Insert(0,i,c);
				Sum+=c;
			}else Insert(i,n+1,-c);
		}
		for(int i=0;i<m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			Insert(u,v,INF);
		}
		int Ans=SAP(0,n+1,n+2);
		printf("%d\n",Sum-Ans);
	}
}
