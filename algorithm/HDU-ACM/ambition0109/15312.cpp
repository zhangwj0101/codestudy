////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 13:43:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1531
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
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
	int u,v,cost;
	Edge(){}
	Edge(int _u,int _v,int c):
		u(_u),v(_v),cost(c){}
}E[M];
int cost[M];
bool vis[M];

bool Bellman(int n,int m){
	memset(cost,0x7f,sizeof(cost));
	bool flag;
	for(int i=0;i<n;i++){
		flag=true;
		for(int j=0;j<m;j++){
			if(cost[E[j].u]+E[j].cost<cost[E[j].v]){
				cost[E[j].v]=cost[E[j].u]+E[j].cost;
				flag=false;
			}
		}
		if(flag) break;
	}
	return flag;
}

int main(){
	int n,m;
	while(scanf("%d",&n),n){
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int t1,t2,diff; char opt[5];
			scanf("%d %d %s %d",&t1,&t2,opt,&diff);
			if(strcmp(opt,"gt")==0){
				E[i]=Edge(t1+t2,t1-1,-diff-1);
			}else{
				E[i]=Edge(t1-1,t1+t2,diff-1);
			}
		}
		if(Bellman(n+1,m)){
			puts("lamentable kingdom");
		}else{
			puts("successful conspiracy");
		}
	}
}
