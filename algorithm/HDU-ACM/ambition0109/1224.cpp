////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-24 12:42:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1224
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*
 * 1224.cpp
 *
 *  Created on: 2010-10-24
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

void swap(int& a,int& b){
	int t=a;a=b;b=t;
}

vector<int> Map[105];
int cost[105];
int take[105];
int pre[105];
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d",&n);
		for(int i=1;i<=n+1;i++){
			Map[i].clear();
			take[i]=-1000000;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&cost[i]);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int c1,c2;
			scanf("%d %d",&c1,&c2);
			if(c1>c2) swap(c1,c2);
			Map[c2].push_back(c1);
		}
		take[n+1]=0;
		for(int i=n+1;i>0;i--){
			int Size=Map[i].size();
			for(int j=0;j<Size;j++){
				if(take[i]+cost[Map[i][j]]>take[Map[i][j]]){
					take[Map[i][j]]=take[i]+cost[Map[i][j]];
					pre[Map[i][j]]=i;
				}
			}
		}
		printf("CASE %d#\n",++cas);
		printf("points : %d\n",take[1]);
		int s=1;
		printf("circuit : ");
		while(s!=n+1){
			printf("%d->",s);
			s=pre[s];
		}
		puts("1");
		if(t) puts("");
	}
}
