////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-11-16 13:27:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1498
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:312KB
//////////////////System Comment End//////////////////
/*
 * 1498.cpp
 *
 *  Created on: 2010-11-16
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=110;

vector<int> Gra[N];
int mat[N],n;
bool Hash[N];

void Init(){
	for(int i=0;i<n;i++){
		Gra[i].clear();
	}
}

bool Find(int t){
	for(unsigned i=0;i<Gra[t].size();i++){
		int v=Gra[t][i];
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
	for(int i=0;i<n;i++){
		memset(Hash,true,sizeof(Hash));
		if(Find(i)) Cnt++;
	}
	return Cnt;
}

bool ball[51];
int Maze[110][110];
int main(){
	int k;
	while(scanf("%d%d",&n,&k),n||k){
		memset(ball,false,sizeof(ball));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&Maze[i][j]);
				ball[Maze[i][j]]=true;
			}
		}
		for(int t=1;t<=50;t++){
			Init();
			if(ball[t]){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if(Maze[i][j]==t){
							Gra[i].push_back(j);
						}
					}
				}
				if(BMM()<=k) ball[t]=false;
			}
		}
		int i; bool flag=true;
		for(i=1;i<=50;i++){
			if(ball[i]){
				flag=false;
				printf("%d",i);
				break;
			}
		}
		if(flag) puts("-1");
		else{
			for(i++;i<=50;i++){
				if(ball[i]){
					printf(" %d",i);
				}
			}
			puts("");
		}
	}
}
