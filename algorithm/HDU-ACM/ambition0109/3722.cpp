////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-28 19:16:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3722
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:1736KB
//////////////////System Comment End//////////////////
/*
 * tju_c.cpp
 *
 *  Created on: 2010-11-23
 *      Author: hduacm
 */

#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=405;

struct Edge{
	int lp,flow,cost,next;
	Edge(){}
	Edge(int _lp,int _flow,int _cost,int _next):
		lp(_lp),flow(_flow),cost(_cost),next(_next){}
}E[999999];
queue<int> que;
int pre[M],cost[M],cur[M];
int head[M],node;
bool vis[M];

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int f,int c){
	E[node]=Edge(v,f,c,head[u]);
	head[u]=node++;
	E[node]=Edge(u,0,-c,head[v]);
	head[v]=node++;
}

int MCF(int s,int t){
	int MCost=0;
	while(true){
		memset(pre,-1,sizeof(pre));
		memset(vis,false,sizeof(vis));
		memset(cost,0x7f,sizeof(cost));
		cost[s]=0;
		que.push(s);
		while(!que.empty()){
			int u=que.front();
			que.pop();
			vis[u]=false;
			for(int i=head[u];i!=-1;i=E[i].next){
				int v=E[i].lp;
				if(E[i].flow&&cost[u]+E[i].cost<cost[v]){
					cost[v]=cost[u]+E[i].cost;
					if(!vis[v]){
						vis[v]=true;
						que.push(v);
					}
					pre[v]=u;
					cur[v]=i;
				}
			}
		}
		if(pre[t]==-1) break;
		for(int v=t;v!=s;v=pre[v]){
			E[cur[v]].flow-=1;
			E[cur[v]^1].flow+=1;
		}
		MCost+=cost[t];
	}
	return MCost;
}

char str[205][1005];
int getval(char sa[],char sb[]){
	int len=strlen(sa),i;
	for(i=1;i<=len;i++){
		if(sa[len-i]!=sb[i-1]){
			return i-1;
		}
	}
	if(i>len) return len;
	return 0;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		Init();
		for(int i=0;i<n;i++){
			scanf("%s",str[i]);
		}
		for(int i=0;i<n;i++){
			Insert(2*n,i,1,0);
			Insert(i+n,2*n+1,1,0);
			for(int j=0;j<n;j++){
				if(i==j) Insert(i,j+n,1,0);
				else{
					int t=getval(str[i],str[j]);
					Insert(i,j+n,1,-t);
				}
			}
		}
		int Ans=-MCF(2*n,2*n+1);
		printf("%d\n",Ans);
	}
}




