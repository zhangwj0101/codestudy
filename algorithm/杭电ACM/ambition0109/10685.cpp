////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 11:29:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*
 * MaxMatch.cpp
 *
 *  Created on: 2010-11-16
 *      Author: hduacm
 */

#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=500;

vector<int> gra[500];
int mat[N],n;
bool Hash[N];

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

int MaxMatch(){
	int Cnt=0;
	memset(mat,-1,sizeof(mat));
	for(int i=0;i<n;i++){
		memset(Hash,true,sizeof(Hash));
		if(Find(i)) Cnt++;
	}
	return Cnt;
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			int s,m;
			gra[i].clear();
			scanf("%d: (%d)",&s,&m);
			for(int j=0;j<m;j++){
				int t;
				scanf("%d",&t);
				gra[s].push_back(t);
			}
		}
		int Ans=MaxMatch();
		printf("%d\n",n-Ans/2);
	}
}
