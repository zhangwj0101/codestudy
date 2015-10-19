////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-07 21:59:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:356KB
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
#define MIN(x,y) (x>y?y:x)

struct Edge{
	int id,val;
	Edge(){}
	Edge(int i,int v):id(i),val(v){}
	friend bool operator <(const Edge& a,const Edge& b){
		return a.val>b.val;
	}
};
int Map[M][M];
bool Hash[M];

int prim(int s,int n){
	int MVal=0,cnt=0;
	memset(Hash,false,sizeof(Hash));
	priority_queue<Edge,vector<Edge> > que;
	que.push(Edge(s,0));
	while(!que.empty()){
		Edge medge=que.top();que.pop();
		if(Hash[medge.id]) continue;
		Hash[medge.id]=true;
		MVal+=medge.val;
		cnt++;
		if(cnt==n) return MVal;
		for(int i=1;i<=n;i++){
			if(Hash[i]) continue;
			que.push(Edge(i,Map[medge.id][i]));
		}
	}
	return -1;
}

int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n*(n-1)/2;i++){
            int u,v,val;
            scanf("%d%d%d",&u,&v,&val);
            Map[u][v]=Map[v][u]=val;
        }
        int Ans=prim(1,n);
        printf("%d\n",Ans);
    }
}
