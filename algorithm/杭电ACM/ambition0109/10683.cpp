////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-09 15:29:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:2187MS
////Run memory:18428KB
//////////////////System Comment End//////////////////
/*
 * 1068.cpp
 *
 *  Created on: 2010-11-9
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

struct Edge{
	int c,val,next;
	Edge(){};
	Edge(int _c,int _val,int _next){
		c=_c; val=_val; next=_next;
	}
}E[9999999];
int head[1000],node=0;

void insert(int s,int t,int val){
	E[node]=Edge(t,val,head[s]);
	head[s]=node++;
	E[node]=Edge(s,0,head[t]);
	head[t]=node++;
}

int que[999999],pre[1000],cur[1000];
int EK(int s,int e,int n){
	int MFlow=0,qs,qe;
	while(true){
		que[qs=qe=0]=s;
		memset(pre,-1,sizeof(pre));
		while(qs<=qe){
			int u=que[qs++];
			for(int v=head[u];v!=-1;v=E[v].next){
				if(E[v].val&&pre[E[v].c]==-1){
					pre[que[++qe]=E[v].c]=u;
					cur[E[v].c]=v;
				}
			}
			if(pre[e]!=-1) break;
		}
		if(pre[e]==-1) break;
		int mf=0x7fffffff;
		for(int t=e;t!=s;t=pre[t]){
			if(E[cur[t]].val<mf){
				mf=E[cur[t]].val;
			}
		}
		for(int t=e;t!=s;t=pre[t]){
			E[cur[t]].val -= mf;
			E[cur[t]^1].val += mf;
		}
		MFlow+=mf;
	}
	return MFlow;
}

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(head,-1,sizeof(head));
		for(int i=0;i<n;i++){
			int t,m;
			scanf("%d: (%d)",&t,&m);
			for(int j=0;j<m;j++){
				int c;
				scanf("%d",&c);
				insert(t,c+n,1);
			}
		}
		for(int i=0;i<n;i++){
			insert(2*n,i,1);
		}
		for(int i=n;i<2*n;i++){
			insert(i,2*n+1,1);
		}
//		for(int i=0;i<2*n+2;i++){
//			printf("%d: ",i);
//			for(int t=head[i];t!=-1;t=E[t].next){
//				printf("%d ",E[t].c);
//			}
//			puts("");
//		}
		int ans=EK(2*n,2*n+1,2*n+2);
		printf("%d\n",n-ans/2);
	}
}
