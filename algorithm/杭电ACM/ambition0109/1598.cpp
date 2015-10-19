////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-27 10:41:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1598
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*
 * 1598.cpp
 *
 *  Created on: 2010-10-27
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct PATH{
	int c1,c2;
	int speed;
}Path[1005];

bool CMP(const PATH& c1,const PATH& c2){
	return c1.speed<c2.speed;
}

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int MFS[205];
int Find(int t){
	if(MFS[t]==t) return t;
	return MFS[t]=Find(MFS[t]);
}

bool Merge(int a,int b){
	int ra=Find(a);
	int rb=Find(b);
	if(ra!=rb){
		MFS[rb]=ra;
		return true;
	}
	return false;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			MFS[i]=i;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&Path[i].c1,&Path[i].c2,&Path[i].speed);
		}
		sort(Path,Path+m,CMP);
		int t; scanf("%d",&t);
		for(int i=0;i<t;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			int MMin=100000;
			for(int j=0;j<m;j++){
				for(int k=1;k<=n;k++){
					MFS[k]=k;
				}
				for(int k=j;k<m;k++){
					Merge(Path[k].c1,Path[k].c2);
					if(Find(c1)==Find(c2)){
						MMin=Min(MMin,Path[k].speed-Path[j].speed);
						break;
					}
				}
			}
			if(MMin!=100000) printf("%d\n",MMin);
			else puts("-1");
		}
	}
}
