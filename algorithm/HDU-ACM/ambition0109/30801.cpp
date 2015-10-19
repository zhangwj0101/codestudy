////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-06 20:40:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3080
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:400KB
//////////////////System Comment End//////////////////
/*
 * 3083.cpp
 *
 *  Created on: 2010-12-6
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 205

int Map[M][M];
bool Hash[M];

void Init(){
	memset(Map,-1,sizeof(Map));
	memset(Hash,false,sizeof(Hash));
}

int Min[M];
int prim(int s,int n,int need){
	for(int i=0;i<n;i++){
		Min[i]=Map[s][i];
	}
	Hash[s]=true;
	int Sum=0,cnt=0;
	while(true){
		int tid=-1,tcost=0x7fffffff;
		for(int i=0;i<n;i++){
			if(Hash[i]) continue;
			if(Min[i]!=-1&&tcost>Min[i]){
				tcost=Min[i];
				tid=i;
			}
		}
		if(tid==-1) return -1;
		Sum+=tcost;
		Hash[tid]=true;
		for(int i=0;i<n;i++){
			if(Hash[i]) continue;
			if(Map[tid][i]!=-1&&(Min[i]==-1||Min[i]>Map[tid][i])){
				Min[i]=Map[tid][i];
			}
		}
		cnt++;
		if(cnt==need-1) break;
	}
	return Sum;
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m,nn,mm,nnn; Init();
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int t1,t2,cost;
			scanf("%d%d%d",&t1,&t2,&cost);
			if(Map[t1][t2]==-1||Map[t1][t2]>cost){
				Map[t1][t2]=Map[t2][t1]=cost;
			}
		}
		scanf("%d%d",&nn,&mm);
		for(int i=0;i<mm;i++){
			int t1,t2,cost;
			scanf("%d%d%d",&t1,&t2,&cost);
			if(Map[t1][t2]==-1||Map[t1][t2]>cost){
				Map[t1][t2]=Map[t2][t1]=cost;
			}
		}
		scanf("%d",&nnn);
		for(int i=0;i<nnn;i++){
			int t;
			scanf("%d",&t);
			Hash[t]=true;
		}
		int id;
		for(int i=0;i<n+nn;i++){
			if(!Hash[i]){
				id=i; break;
			}
		}
		int Ans=prim(id,n+nn,n+nn-nnn);
		if(Ans==-1) puts("what a pity!");
		else printf("%d\n",Ans);
	}
}
