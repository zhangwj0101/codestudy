////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-08 19:01:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1384
////Problem Title: 
////Run result: Accept
////Run time:1609MS
////Run memory:1360KB
//////////////////System Comment End//////////////////
/*
 * 1201.cpp
 *
 *  Created on: 2010-12-8
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define M 50010

struct Edge{
	int id,val,next;
	Edge(){}
	Edge(int i,int v,int n):
		id(i),val(v),next(n){}
}E[999999];
int head[M],node;
int cost[M];
bool vis[M];

void Init(){
	memset(head,-1,sizeof(head));
	node=0;
}

void Insert(int u,int v,int c){
	E[node]=Edge(v,c,head[u]);
	head[u]=node++;
}

bool SPFA(int s,int min,int max){
	memset(cost,-1,sizeof(cost));
	memset(vis,false,sizeof(vis));
	cost[s]=0;
	queue<int> que;
	que.push(s);
	while(!que.empty()){
		int u=que.front(); que.pop();
		vis[u]=false;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(E[i].val+cost[u]>cost[v]){
				cost[v]=E[i].val+cost[u];
				if(!vis[v]){
					que.push(v);
					vis[v]=true;
				}
			}
		}
		if(u+1<=max&&cost[u+1]<cost[u]){
			cost[u+1]=cost[u];
			if(!vis[u+1]){
				que.push(u+1);
				vis[u+1]=true;
			}
		}
		if(u-1>=min&&cost[u-1]+1<cost[u]){
			cost[u-1]=cost[u]-1;
			if(!vis[u-1]){
				que.push(u-1);
				vis[u-1]=true;
			}
		}
	}
	return true;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		Init();
		int min=50001,max=0;
		for(int i=0;i<n;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Insert(a,b+1,c);
			if(a<min) min=a;
			if(b+1>max) max=b+1;
		}
		SPFA(min,min,max);
		printf("%d\n",cost[max]);
	}
}

