////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-14 16:06:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3718
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:304KB
//////////////////System Comment End//////////////////
/*
 * 3718.cpp
 *
 *  Created on: 2010-12-14
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 55
#define INF 0x7fffffff

inline void in(char& val){
	char in;
	do{ in=getchar();
	}while(in<'A'||in>'Z');
	val=in;
}

struct Edge {
	int lp, flow, cost, next;
	Edge() {}
	Edge(int _lp, int _flow, int _cost, int _next) :
		lp(_lp), flow(_flow), cost(_cost), next(_next) {}
} E[999999];
queue<int> que;
int pre[M], cost[M], cur[M];
int head[M], node;
bool vis[M];

void Init() {
	memset(head, -1, sizeof(head));
	node = 0;
}

void Insert(int u, int v, int f, int c) {
	E[node] = Edge(v, f, c, head[u]);
	head[u] = node++;
	E[node] = Edge(u, 0, -c, head[v]);
	head[v] = node++;
}

int MCF(int s, int t) {
	int MCost = 0;
	while (true) {
		memset(pre, -1, sizeof(pre));
		memset(vis, false, sizeof(vis));
		memset(cost, 0x7f, sizeof(cost));
		cost[s] = 0;
		que.push(s);
		while (!que.empty()) {
			int u = que.front();
			que.pop();
			vis[u] = false;
			for (int i = head[u]; i != -1; i = E[i].next) {
				int v = E[i].lp;
				if (E[i].flow && cost[u] + E[i].cost < cost[v]) {
					cost[v] = cost[u] + E[i].cost;
					if (!vis[v]) {
						vis[v] = true;
						que.push(v);
					}
					pre[v] = u;
					cur[v] = i;
				}
			}
		}
		if (pre[t] == -1) break;
		for (int v = t; v != s; v = pre[v]) {
			E[cur[v]].flow -= 1;
			E[cur[v] ^ 1].flow += 1;
		}
		MCost += cost[t];
	}
	return MCost;
}

char base[10005],tch;
int val[30][30];
bool hasx[M],hasy[M];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m,k;
		scanf("%d%d%d",&n,&k,&m);
		memset(hasx,false,sizeof(hasx));
		for(int i=0;i<n;i++){
			in(base[i]);
			hasx[base[i]-'@']=true;
		}
		for(int i=0;i<m;i++){
			memset(val,0,sizeof(val));
			memset(hasy,false,sizeof(hasy));
			for(int j=0;j<n;j++){
				in(tch);
				hasy[tch-'@']=true;
				val[base[j]-'@'][tch-'@']++;
			}
			Init();
			for(int ii=1;ii<27;ii++){
				if(hasx[ii]){
					Insert(0,ii,1,0);
				}
				if(hasy[ii]){
					Insert(ii+26,53,1,0);
				}
				for(int jj=1;jj<27;jj++){
					if(val[ii][jj]){
						Insert(ii,jj+26,1,-val[ii][jj]);
					}
				}
			}
			int v=-MCF(0,53);
			printf("%.4lf\n",double(v)/n);
		}
	}
}
