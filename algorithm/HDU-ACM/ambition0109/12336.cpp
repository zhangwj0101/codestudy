////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 12:40:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:528KB
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
vector<Edge> Gra[M];

bool Hash[M];
int N;
int prim(int s){
	int MVal=0,t=1;
	priority_queue<Edge,vector<Edge> > que;
	for(unsigned i=0;i<Gra[s].size();i++){
		que.push(Gra[s][i]);
	}
	memset(Hash,false,sizeof(Hash));
	Hash[s]=true;
	while(t!=N){
		Edge tmp=que.top();
		que.pop();
		if(Hash[tmp.lp]) continue;
		for(unsigned i=0;i<Gra[tmp.lp].size();i++){
			if(Hash[Gra[tmp.lp][i].lp]) continue;
			que.push(Gra[tmp.lp][i]);
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
		for(int i=1;i<=n;i++){
			Gra[i].clear();
		}
		for(int i=0;i<n*(n-1)/2;i++){
			int u,v,val;
			scanf("%d%d%d",&u,&v,&val);
			Gra[u].push_back(Edge(v,val));
			Gra[v].push_back(Edge(u,val));
		}
		N=n;
		int Ans=prim(1);
		printf("%d\n",Ans);
	}
}
