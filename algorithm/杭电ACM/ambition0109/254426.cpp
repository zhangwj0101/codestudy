////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-08 16:38:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
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
	E[node]=Edge(u,c,head[v]);
	head[v]=node++;
}

bool SPFA(int s,int n){
	memset(cost,-1,sizeof(cost));
	memset(vis,false,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	cost[s]=0; cnt[s]=1;
	que[ss=ee=0]=s;
	while(ss<=ee){
		int u=que[ss++];
		vis[u]=false;
		for(int i=head[u];i!=-1;i=E[i].next){
			int v=E[i].id;
			if(cost[v]==-1||E[i].val+cost[u]<cost[v]){
				cost[v]=E[i].val+cost[u];
				if((++cnt[v])>n) return false;
				if(!vis[v]){
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
	while(scanf("%d%d",&n,&m),n||m){
		Init();
		for(int i=0;i<m;i++){
			int c1,c2,cost;
			scanf("%d%d%d",&c1,&c2,&cost);
			Insert(c1,c2,cost);
		}
		SPFA(1,n);
		printf("%d\n",cost[n]);
	}
}
