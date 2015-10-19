////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-12 14:26:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3081
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:500KB
//////////////////System Comment End//////////////////
/*
 * 3081.cpp
 *
 *  Created on: 2010-11-12
 *      Author: amb
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define clr(a,b) (memset(a,b,sizeof(a)))
const int N=205;

int tmp[205][205];
int Idx[105];
int Find(int t){
	if(Idx[t]==t) return t;
	return Idx[t]=Find(Idx[t]);
}

bool Merge(int a,int b){
	int ra=Find(a);
	int rb=Find(b);
	if(ra==rb) return false;
	Idx[rb]=ra;
	return true;
}

int pre[N], map[N][N], cur[N], gap[N], dis[N];
inline int Min(int a,int b) {return a<b?a:b;}
int sap (int nodenum, int s, int t) {
	clr (dis, 0);
	clr (gap, 0);
	clr (cur, 0);
	int u = pre[s] = s, v, maxflow = 0;
	int mi = 0x7fffffff;
	gap[0] = nodenum;
	while (dis[s] < nodenum) {
		loop:
		for (v = cur[u];v <= nodenum;v++) {//0~n-1:< 1~n <=
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
					mi = 0x7fffffff;
				}
				goto loop;
			}
		}
		int mindis = nodenum - 1;
		for (v = 1;v <= nodenum;v++) {
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
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y;
		memset(tmp,0,sizeof(tmp));
		scanf("%d%d%d",&n,&x,&y);
		for(int i=1;i<=n;i++){
			Idx[i]=i;
		}
		for(int i=0;i<x;i++){
			int g,b;
			scanf("%d%d",&g,&b);
			tmp[g][b+n]=1;
		}
		for(int i=0;i<y;i++){
			int g1,g2;
			scanf("%d%d",&g1,&g2);
			Merge(g1,g2);
		}
		for(int i=1;i<=n;i++){
			int r=Find(i);
			if(r==i) continue;
			for(int j=n+1;j<=2*n;j++){
				if(tmp[i][j]){
					tmp[r][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			int r=Find(i);
			if(i==r) continue;
			for(int j=n+1;j<=2*n;j++){
				if(tmp[r][j]){
					tmp[i][j]=1;
				}
			}
		}
		int top=0,bot=n;
		int mid=(top+bot)>>1,ans=mid;
		while(top<=bot){
			for(int i=0;i<=2*n+1;i++){
				for(int j=0;j<=2*n+1;j++){
					map[i][j]=tmp[i][j];
				}
			}
			for(int i=1;i<=n;i++){
				map[0][i]=mid;
				map[i+n][2*n+1]=mid;
			}
			int mf=sap(2*n+2,0,2*n+1);
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
