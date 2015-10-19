////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-11 21:06:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1534
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*
 * 1534.cpp
 *
 *  Created on: 2010-12-11
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int _u,int _v,int _w):
		u(_u),v(_v),w(_w){}
}E[99999];
int dis[1000];

bool Bellman_Ford(int n,int t){
	memset(dis,0x80,sizeof(dis));
	dis[0]=0;
	bool flag;
	for(int i=0;i<=n;i++){
		flag=true;
		for(int j=0;j<t;j++){
			if(dis[E[j].v]<dis[E[j].u]+E[j].w){
				dis[E[j].v]=dis[E[j].u]+E[j].w;
				flag=false;
			}
		}
		if(flag) break;
	}
	return flag;
}

int last[1000];
int main(){
	int n,cas=0;
	while(scanf("%d",&n),n){
		int t=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&last[i]);
			E[t++]=Edge(0,i,0);
		}
		char cmd[5];
		while(scanf("%s",cmd),strcmp(cmd,"#")){
			int u,v;
			scanf("%d%d",&v,&u);
			if(strcmp(cmd,"SAF")==0){
				E[t++]=Edge(u,v,last[u]);
			}else if(strcmp(cmd,"FAF")==0){
				E[t++]=Edge(u,v,last[u]-last[v]);
			}else if(strcmp(cmd,"FAS")==0){
				E[t++]=Edge(u,v,-last[v]);
			}else if(strcmp(cmd,"SAS")==0){
				E[t++]=Edge(u,v,0);
			}
		}
		printf("Case %d:\n",++cas);
		if(Bellman_Ford(n+1,t)){
			for(int i=1;i<=n;i++){
				printf("%d %d\n",i,dis[i]);
			}
		}else{
			puts("impossible");
		}
		puts("");
	}
}
