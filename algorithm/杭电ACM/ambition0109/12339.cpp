////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 12:47:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:372KB
//////////////////System Comment End//////////////////
/*
 * prim.cpp
 *
 *  Created on: 2010-11-25
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define M 105
#define INF 0x7fffffff
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int lp,val;
	Edge(){}
	Edge(int _lp,int _val):
		lp(_lp),val(_val){}
	friend bool operator <(const Edge& a,const Edge& b){
		return a.val>b.val;
	}
};
int Map[M][M];

bool Hash[M];
int N;
int prim(int s){
	int MVal=0,t=1;
	priority_queue<Edge,vector<Edge> > que;
	for(int i=1;i<=N;i++){
		if(i==s) continue;
		que.push(Edge(i,Map[s][i]));
	}
	memset(Hash,false,sizeof(Hash));
	Hash[s]=true;
	while(t!=N){
		Edge tmp=que.top();
		que.pop();
		if(Hash[tmp.lp]) continue;
		for(int i=1;i<=N;i++){
			if(Hash[i]) continue;
			if(i==s) continue;
			que.push(Edge(i,Map[tmp.lp][i]));
		}
		Hash[tmp.lp]=true;
		MVal+=tmp.val;
		t++;
	}
	return MVal;
}

int main(){
	int n;
	while(scanf("%d",&n),n){
		for(int i=0;i<n*(n-1)/2;i++){
			int u,v,val;
			scanf("%d%d%d",&u,&v,&val);
			Map[u][v]=Map[v][u]=val;
		}
		N=n;
		int Ans=prim(1);
		printf("%d\n",Ans);
	}
}
