////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 15:42:51
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*
 * 1241.cpp
 *
 *  Created on: 2010-11-25
 *      Author: hduacm
 */

#include<cstdio>
using namespace std;
int dir[8][2]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
int n,m,sum;
char Map[105][105];

void sw(int x,int y){
	for(int i=0;i<8;i++){
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if(tx<0||ty<0||tx>=n||ty>=m) continue;
		if(Map[tx][ty]=='*') continue;
		if(Map[tx][ty]=='@'){
			Map[tx][ty]='*';
			sw(tx,ty);
			sum--;
		}
	}
}

int main(){
	while(scanf("%d%d",&n,&m),n||m){
		sum=0;
		for(int i=0;i<n;i++){
			scanf("%s",Map[i]);
			for(int j=0;j<m;j++){
				if(Map[i][j]=='@'){
					sum++;
				}
			}
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(Map[i][j]=='@'){
					cnt++;
					sw(i,j);
					if(sum==0) break;
				}
			}
			if(sum==0) break;
		}
		printf("%d\n",cnt);
	}
}