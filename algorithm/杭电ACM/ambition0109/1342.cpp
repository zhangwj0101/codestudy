////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-19 15:24:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1342
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*
 * 1342.cpp
 *
 *  Created on: 2010-11-19
 *      Author: hduacm
 */

/*
 * 1342.cpp
 *
 *  Created on: 2010-11-19
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;

int n,num[15];
bool Hash[15];
void dfs(int t,int p){
	if(t==6){
		bool f=false;
		for(int i=0;i<n;i++){
			if(Hash[i]){
				if(f) printf(" ");
				f=true;
				printf("%d",num[i]);
			}
		}
		puts("");
	}
	for(int i=p+1;i<n;i++){
		Hash[i]=true;
		dfs(t+1,i);
		Hash[i]=false;
	}
}

int main(){
	bool f=false;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		if(f) puts("");
		f=true;
		memset(Hash,false,sizeof(Hash));
		dfs(0,-1);
	}
}
