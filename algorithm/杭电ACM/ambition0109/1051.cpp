////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-29 17:49:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
/*
 * 1051.cpp
 *
 *  Created on: 2010-10-29
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node{
	int l,w;
}node[5005];

bool CMP(const Node& a,const Node& b){
	return a.l<b.l;
}

int Dp[5005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&node[i].l,&node[i].w);
		}
		sort(node,node+n,CMP);
		memset(Dp,0,sizeof(Dp));
		int m=1;
		for(int i=0;i<n;i++){
			bool flag=true;
			for(int j=0;j<m;j++){
				if(node[i].w>=Dp[j]){
					Dp[j]=node[i].w;
					flag=false;
					break;
				}
			}
			if(flag){
				Dp[m++]=node[i].w;
			}
		}
		printf("%d\n",m);
	}
}
