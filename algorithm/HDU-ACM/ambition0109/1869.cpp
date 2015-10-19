////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-01 20:12:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*
 * 1869.cpp
 *
 *  Created on: 2010-10-1
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 100

int n;
int Map[MAXN+1][MAXN+1];
void Init(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			Map[i][j]=-(i!=j);
		}
	}
}

void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(Map[i][k]==-1) continue;
			for(int j=0;j<n;j++){
				if(Map[k][j]==-1) continue;
				if(Map[i][j]==-1||Map[i][j]>Map[i][k]+Map[k][j]){
					Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}
	}
}

int main(){
	int m;
	while(scanf("%d%d",&n,&m)!=EOF){
		Init();
		for(int i=0;i<m;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Map[c1][c2]=Map[c2][c1]=1;
		}
		floyd();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(Map[i][j]==-1||Map[i][j]>7){
					goto NO;
				}
			}
		}
		puts("Yes");
		continue;
		NO:
		puts("No");
	}
}
