////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-21 15:42:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3342
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:256KB
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

vector<vector<int> > Graph;
queue<int> Que;
int Deg[110];
bool Topological(int n){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(!Deg[i]){
			Que.push(i);
			cnt++;
		}
	}
	while(!Que.empty()){
		int top=Que.front();
		int size=Graph[top].size();
		Que.pop();
		for(int i=0;i<size;i++){
			int link=Graph[top][i];
			Deg[link]--;
			if(Deg[link]==0){
				Que.push(link);
				cnt++;
			}
		}
	}
	if(cnt<n) return false;
	return true;
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		Graph.clear();
		Graph.resize(n);
		memset(Deg,0,sizeof(Deg));
		for(int i=0;i<m;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Graph[c1].push_back(c2);
			Deg[c2]++;
		}
		bool ans=Topological(n);
		puts(ans?"YES":"NO");
	}
}
