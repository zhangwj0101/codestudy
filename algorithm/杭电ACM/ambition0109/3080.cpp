////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-06 19:51:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3080
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:304KB
//////////////////System Comment End//////////////////
/*
 * 3080.cpp
 *
 *  Created on: 2010-12-6
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define M 205

struct Link{
	int t1,t2,cost;
	friend bool operator <(const Link& a,const Link& b){
		return a.cost<b.cost;
	}
}L[99999];
bool Hash[M];

int Idx[M];
int Find(int t){
	if(Idx[t]==t) return t;
	return Idx[t]=Find(Idx[t]);
}

bool Merge(int t1,int t2){
	int r1=Find(t1);
	int r2=Find(t2);
	if(r1==r2) return false;
	Idx[r2]=r1;
	return true;
}

void Init(){
	for(int i=0;i<M;i++){
		Idx[i]=i;
	}
	memset(Hash,false,sizeof(Hash));
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,m,nn,mm; Init();
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&L[i].t1,&L[i].t2,&L[i].cost);
		}
		scanf("%d%d",&nn,&mm);
		for(int i=0;i<mm;i++){
			scanf("%d%d%d",&L[m+i].t1,&L[m+i].t2,&L[m+i].cost);
		}
		int nnn;
		scanf("%d",&nnn);
		for(int i=0;i<nnn;i++){
			int t;
			scanf("%d",&t);
			Hash[t]=true;
		}
		sort(L,L+m+mm);
		int cnt=0,Sum=0;
		for(int i=0;i<m+mm;i++){
			if(Hash[L[i].t1]) continue;
			if(Hash[L[i].t2]) continue;
			if(Merge(L[i].t1,L[i].t2)){
				Sum+=L[i].cost;
				cnt++;
			}
			if(cnt==n+nn-nnn-1) break;
		}
		if(cnt<n+nn-nnn-1) puts("what a pity!");
		else printf("%d\n",Sum);
	}
}
