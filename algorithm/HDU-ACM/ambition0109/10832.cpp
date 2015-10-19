////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-27 12:25:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1083
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:448KB
//////////////////System Comment End//////////////////
/*
 * 1083G.cpp
 *
 *  Created on: 2010-11-27
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define M 500

vector<int> gra[M];
int mat[M],N;
bool Hash[M];

bool Find(int t){
	for(unsigned i=0;i<gra[t].size();i++){
		int v=gra[t][i];
		if(Hash[v]){
			Hash[v]=false;
			if(mat[v]==-1||Find(mat[v])){
				mat[v]=t;
				return true;
			}
		}
	}
	return false;
}

int Edmonds(){
	int cnt=0;
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<N;i++){
		memset(Hash,true,sizeof(Hash));
		if(Find(i)){
			cnt++;
		}
	}
	return cnt;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int &n=N,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			gra[i].clear();
			int s;
			scanf("%d",&s);
			for(int j=0;j<s;j++){
				int v;
				scanf("%d",&v);
				gra[i].push_back(v+n-1);
			}
		}
	//	printf("## %d\n",Edmonds());
		puts(Edmonds()==n?"YES":"NO");
	}
}
