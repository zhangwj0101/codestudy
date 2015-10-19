////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-20 12:33:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3741
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:208KB
//////////////////System Comment End//////////////////
/*
 * 3741.cpp
 *
 *  Created on: 2010-12-20
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

double val[105],sum;
bool vis[105];int n;
bool Dfs(int s,double v){
	if(s>=n) return false;
	double dif=(sum-(v+val[s]))/(v+val[s]);
	if(dif<=1.015&&dif>=0.985){
		vis[s]=true;
		return true;
	}
	if((v+val[s])*2.0<=sum){
		vis[s]=true;
		if(Dfs(s+1,v+val[s])) return true;
		vis[s]=false;
	}
	if(Dfs(s+1,v)) return true;
	return false;
}

int main(){

	while(scanf("%d",&n),n){
		sum=0;
		memset(vis,false,sizeof(vis));
		for(int i=0;i<n;i++){
			scanf("%lf",&val[i]);
			sum+=val[i];
		}
		Dfs(0,0);
		bool flag=false;
		for(int i=0;i<n;i++){
			if(vis[i]){
				if(flag) printf(" ");
				printf("%d",i+1);
				flag=true;
			}
		}
		puts("");
	}
}
