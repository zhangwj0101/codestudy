////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 13:06:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1531
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*
 * 1521.cpp
 *
 *  Created on: 2010-12-11
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define M 105

struct Edge{
	int id,val,next;
	Edge(){}
	Edge(int i,int v,int n):
		id(i),val(v),next(n){}
}E[999999];
int que[999999],ss,ee;
int head[M],node;
int cost[M],cnt[M];
bool vis[M];

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int c){
	E[node]=Edge(v,c,head[u]);
	head[u]=node++;
}

bool SPFA(int s,int n){
	memset(cost,0x7f,sizeof(cost));
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	cost[s]=0; cnt[s]=1;
	que[ss=ee=0]=s;
	while(ss<=ee){
		int u=que[ss++];
		vis[u]=false;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(E[i].val+cost[u]<cost[v]){
				cost[v]=E[i].val+cost[u];
				if(!vis[v]){
					if((++cnt[v])>n) return false;
					que[++ee]=v;
					vis[v]=true;
				}
			}
		}
	}
	return true;
}

int main(){
	int n,m;
	while(scanf("%d",&n),n){
		scanf("%d",&m); Init();
		for(int i=0;i<m;i++){
			int t1,t2,diff; char opt[5];
			scanf("%d %d %s %d",&t1,&t2,opt,&diff);
			if(strcmp(opt,"gt")==0){
				Insert(t1+t2,t1-1,-diff-1);
			}else{
				Insert(t1-1,t1+t2,diff-1);
			}
		}
		for(int i=0;i<=n;i++){
			Insert(n+1,i,0);
		}
		if(SPFA(n+1,n+2)){
			puts("lamentable kingdom");
		}else{
			puts("successful conspiracy");
		}
	}
}
