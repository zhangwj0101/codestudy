////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-09 14:17:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:3000MS
////Run memory:4156KB
//////////////////System Comment End//////////////////
/*
 * 1068.cpp
 *
 *  Created on: 2010-11-9
 *      Author: hduacm
 */

#include <stdio.h>
#include <string.h>
#define clr(a,b) (memset(a,b,sizeof(a)))
const int inf = 0x7f7f7f7f;
const int N = 1005;
int pre[N], map[N][N], cur[N], gap[N], dis[N];
inline int Min(int a,int b) {return a<b?a:b;}
int sap (int nodenum, int s, int t) {
	clr (dis, 0);
	clr (gap, 0);
	clr (cur, 0);
	int u = pre[s] = s, v, maxflow = 0;
	int mi = inf;
	gap[0] = nodenum;
	while (dis[s] < nodenum) {
		loop:
		for (v = cur[u];v < nodenum;v++) {
			if (map[u][v] && dis[u] == dis[v] + 1) {
				mi = Min (mi, map[u][v]);
				pre[v] = u;
				u = cur[u] = v;
				if (v == t) {
					maxflow += mi;
					for (u = pre[u];v != s;v = u, u = pre[u]) {
						map[u][v] -= mi;
						map[v][u] += mi;
					}
					mi = inf;
				}
				goto loop;
			}
		}
		int mindis = nodenum - 1;
		for (v = 0;v < nodenum;v++) {
			if (map[u][v] && mindis > dis[v]) {
				cur[u] = v;
				mindis = dis[v];
			}
		}
		if ( (--gap[dis[u]]) == 0) break;
		gap[dis[u] = mindis + 1]++;
		u = pre[u];
	}
	return maxflow;
}


int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(map,0,sizeof(map));
		for(int i=0;i<n;i++){
			int t,m;
			scanf("%d: (%d)",&t,&m);
			for(int j=0;j<m;j++){
				int c;
				scanf("%d",&c);
				map[t][c+n]=1;
			}
		}
		for(int i=0;i<n;i++){
			map[2*n][i]=1;
		}
		for(int i=n;i<2*n;i++){
			map[i][2*n+1]=1;
		}
		int ans=sap(2*n+2,2*n,2*n+1);
		printf("%d\n",n-ans/2);
	}
}
