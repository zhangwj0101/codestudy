////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-21 16:09:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3342
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*
 * 3342.cpp
 *
 *  Created on: 2010-10-21
 *      Author: administrator
 */

#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<int> Graph[110];
queue<int> Que;
int Deg[110];
bool Topo_sort(int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(!Deg[i]) Que.push(i);
	}
	while(!Que.empty()){
		int top=Que.front();
		int size=Graph[top].size();
		Que.pop(); cnt++;
		for(int i=0;i<size;i++){
			int link=Graph[top][i];
			Deg[link]--;
			if(!Deg[link]) Que.push(link);
		}
	}
	return cnt==n;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		for(int i=0;i<n;i++){
			Graph[i].clear();
		}
		memset(Deg,0,sizeof(Deg));
		for(int i=0;i<m;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Graph[c1].push_back(c2);
			Deg[c2]++;
		}
		bool Ans=Topo_sort(n);
		puts(Ans?"YES":"NO");
	}
}
