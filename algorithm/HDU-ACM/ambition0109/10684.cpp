////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 11:26:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1068
////Problem Title: 
////Run result: Accept
////Run time:1031MS
////Run memory:4124KB
//////////////////System Comment End//////////////////
/*
 * MaxMatch.cpp
 *
 *  Created on: 2010-11-16
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
const int N=1000;

int gra[N][N],mat[N],n;
bool Hash[N];

bool Find(int t){
	for(int i=0;i<n;i++){
		if(gra[t][i]&&Hash[i]){
			Hash[i]=false;
			if(mat[i]==-1||Find(mat[i])){
				mat[i]=t;
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
		memset(gra,0,sizeof(gra));
		for(int i=0;i<n;i++){
			int s,m;
			scanf("%d: (%d)",&s,&m);
			for(int j=0;j<m;j++){
				int t;
				scanf("%d",&t);
				gra[s][t]=1;
			}
		}
		int Ans=MaxMatch();
		printf("%d\n",n-Ans/2);
	}
}
