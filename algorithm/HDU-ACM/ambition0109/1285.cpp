////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-21 15:56:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1285
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:280KB
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

vector<int> Graph[510];
priority_queue<int,vector<int>,greater<int> > Que;
queue<int> Ans;
int Deg[510];
bool Topological(int n){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!Deg[i]){
			Que.push(i);
			cnt++;
		}
	}
	while(!Que.empty()){
		int top=Que.top();
		int size=Graph[top].size();
		Ans.push(top);
		Que.pop();
		for(int i=0;i<size;i++){
			int link=Graph[top][i];
			Deg[link]--;
			if(!Deg[link]){
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
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;i++){
			Graph[i].clear();
		}
		memset(Deg,0,sizeof(Deg));
		for(int i=0;i<m;i++){
			int c1,c2;
			scanf("%d%d",&c1,&c2);
			Graph[c1].push_back(c2);
			Deg[c2]++;
		}
		Topological(n);
		printf("%d",Ans.front());
		Ans.pop();
		while(!Ans.empty()){
			printf(" %d",Ans.front());
			Ans.pop();
		}
		puts("");
	}
}
