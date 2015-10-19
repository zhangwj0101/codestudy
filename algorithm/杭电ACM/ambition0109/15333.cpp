////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-10 19:24:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1533
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:556KB
//////////////////System Comment End//////////////////
/*
 * 11-10.cpp
 *
 *  Created on: 2010-11-10
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

struct Pos{
	int x,y;
}H[105],M[105];

struct Edge{
	int lc,flow,cost,next;
	Edge(){}
	Edge(int _l,int _f,int _c,int _n):
		lc(_l),flow(_f),cost(_c),next(_n){
	}
}E[999999];

bool Hash[205];
int pre[205],dis[205],cur[205];
int que[9999999],nn;
int head[205],node;

int Abs(const int& a){
	int temp=(a>>31);
	return (a+temp)^temp;
}

void Insert(int s,int t,int flow,int cost){
	E[node]=Edge(t,flow,cost,head[s]);
	head[s]=node++;
	E[node]=Edge(s,0,-cost,head[t]);
	head[t]=node++;
}

bool SPFA(int s,int t){
	memset(dis,0x7f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	memset(Hash,false,sizeof(Hash));
	dis[s]=0; que[0]=s;
	int qs=0,qe=0;
	while(qs<=qe){
		int u=que[qs++];
		Hash[u]=false;
		for(int i=head[u];i!=-1;i=E[i].next){
			int tc=E[i].lc;
			if(E[i].flow&&dis[u]+E[i].cost<dis[tc]){
				dis[tc]=dis[u]+E[i].cost;
				if(!Hash[tc]){
					que[++qe]=tc;
					Hash[tc]=true;
				}
				pre[tc]=u;
				cur[tc]=i;
			}
		}
	}
	if(pre[t]!=-1) return true;
	else return false;
}

int MCF(int s,int t){
	int Sum=0;
	while(SPFA(s,t)){
		int k=t;
		while(k!=s){
			E[cur[k]].flow-=1;
			E[cur[k]^1].flow+=1;
			k=pre[k];
		}
		Sum+=dis[t];
	}
	return Sum;
}

int main(){
	char str[105];
	int c,r;
	while(scanf("%d%d",&c,&r),c||r){
		node=0;
		memset(head,-1,sizeof(head));
		int h=0,m=0;
		for(int i=0;i<c;i++){
			scanf("%s",str);
			for(int j=0;j<r;j++){
				if(str[j]=='H'){
					H[h].x=i;
					H[h++].y=j;
				}else if(str[j]=='m'){
					M[m].x=i;
					M[m++].y=j;
				}
			}
		}
		int n=h;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				Insert(i,j+n,1,Abs(int(H[i].x-M[j].x))+Abs(int(H[i].y-M[j].y)));
			}
		}
		for(int i=0;i<n;i++){
			Insert(n*2,i,1,0);
			Insert(i+n,n*2+1,1,0);
		}
		nn=n*2+2;
		int Ans=MCF(2*n,2*n+1);
		printf("%d\n",Ans);
	}
}
