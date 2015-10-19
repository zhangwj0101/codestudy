////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-14 14:07:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3605
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:2188KB
//////////////////System Comment End//////////////////
/*
 * 3605.cpp
 *
 *  Created on: 2010-12-14
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
using namespace std;
#define MX 100005
#define MY 12

bool gra[MX][MY],Hash[MY];
int mat[MY][MX],cap[MY],take[MY];
int n,m;

bool Find(int u){
	for(int v=0;v<m;v++){
		if(Hash[v]&&gra[u][v]){
			Hash[v]=false;
			if(cap[v]>take[v]){
				mat[v][take[v]++]=u;
				return true;
			}else{
				for(int i=0;i<cap[v];i++){
					if(Find(mat[v][i])){
						mat[v][i]=u;
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool Edmonds(){
	memset(take,0,sizeof(take));
	for(int i=0;i<n;i++){
		memset(Hash,true,sizeof(Hash));
		if(!Find(i)) return false;
	}
	return true;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				int tmp;
				scanf("%d",&tmp);
				if(tmp) gra[i][j]=true;
				else gra[i][j]=false;
			}
		}
		for(int i=0;i<m;i++){
			scanf("%d",&cap[i]);
		}
		puts(Edmonds()?"YES":"NO");
	}
}
