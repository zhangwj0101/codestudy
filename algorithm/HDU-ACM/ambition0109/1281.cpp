////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 12:24:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1281
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*
 * 1281.cpp
 *
 *  Created on: 2010-11-16
 *      Author: hduacm
 */

#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=110;

vector<int> Gra[N];
int n,m;
int mat[N];
bool Hash[N];

bool Find(int t){
	for(unsigned i=0;i<Gra[t].size();i++){
		int v=Gra[t][i];
		if(v==-1) continue;
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

int BMM(){
	int Cnt=0;
	memset(mat,-1,sizeof(mat));
	for(int i=1;i<=n;i++){
		memset(Hash,true,sizeof(Hash));
		if(Find(i)) Cnt++;
	}
	return Cnt;
}

int main(){
	int k,cas=0;
	while(~scanf("%d%d%d",&n,&m,&k)){
		for(int i=1;i<=n;i++){
			Gra[i].clear();
		}
		for(int i=0;i<k;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Gra[c1].push_back(c2);
		}
		int Max=BMM(),imp=0;
		for(int i=1;i<=n;i++){
			for(unsigned j=0;j<Gra[i].size();j++){
				int tmp=Gra[i][j];
				Gra[i][j]=-1;
				if(BMM()!=Max) imp++;
//				printf("== %d %d\n",i,BMM());
				Gra[i][j]=tmp;
			}
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",++cas,imp,Max);
	}
}
