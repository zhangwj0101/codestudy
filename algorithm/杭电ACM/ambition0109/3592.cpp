////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-15 14:25:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3592
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:368KB
//////////////////System Comment End//////////////////
/*
 * 3592.cpp
 *
 *  Created on: 2010-12-15
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define N 1005
#define M 20005

int uu[M],vv[M],val[M];
int cost[N];

bool Bellman_Ford(int n,int m){
	memset(cost,0x7f,sizeof(cost));
	cost[1]=0;
	bool flag;
	for(int i=0;i<=n;i++){
		flag=true;
		for(int j=0;j<m;j++){
			if(cost[uu[j]]+val[j]<cost[vv[j]]){
				cost[vv[j]]=cost[uu[j]]+val[j];
				flag=false;
			}
		}
		for(int j=n;j>1;j--){
			if(cost[j]<cost[j-1]){
				cost[j-1]=cost[j];
				flag=false;
			}
		}
		if(flag) break;
	}
	return flag;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y;
		scanf("%d%d%d",&n,&x,&y);
		for(int i=0;i<x;i++){
			scanf("%d%d%d",&uu[i],&vv[i],&val[i]);

		}
		for(int i=0;i<y;i++){
			scanf("%d%d%d",&vv[i+x],&uu[i+x],&val[i+x]);
			val[i+x]=-val[i+x];
		}
		if(Bellman_Ford(n,x+y)){
			if(cost[n]==0x7f7f7f7f){
				puts("-2");
			}else{
				printf("%d\n",cost[n]);
			}
		}else{
			puts("-1");
		}
	}
}
