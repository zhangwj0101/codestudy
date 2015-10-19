////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-25 20:22:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
/*
 * 1312.cpp
 *
 *  Created on: 2010-11-25
 *      Author: hduacm
 */

#include<cstdio>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int cnt,n,m;
char Map[25][25];

void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int tx=x+dir[i][0],ty=y+dir[i][1];
		if(tx<0||ty<0||tx>=n||ty>=m) continue;
		if(Map[tx][ty]=='#') continue;
		Map[tx][ty]='#'; cnt++;
		dfs(tx,ty);

	}
}

int main(){
	while(scanf("%d%d",&m,&n),n||m){
		int sx,sy;
		for(int i=0;i<n;i++){
			scanf("%s",Map[i]);
			for(int j=0;j<m;j++){
				if(Map[i][j]=='@'){
					sx=i,sy=j;
					Map[i][j]='#';
				}
			}
		}
		cnt=1;
		dfs(sx,sy);
		printf("%d\n",cnt);
	}

}
