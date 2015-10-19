////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-10-22 19:30:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3452
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:4292KB
//////////////////System Comment End//////////////////
/*
 * 3452.cpp
 *
 *  Created on: 2010-10-22
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Node{
	int point,cost;
};
vector<int> Tree[1010];
int Cost[1010][1010];
bool Hash[1010];

int Min(const int& a,const int& b){
	int dif=b-a;
	return a+(dif&(dif>>31));
}

int Dfs(int s){
	int Size=Tree[s].size();
	int Sum=0; bool flag=false;
	for(int i=0;i<Size;i++){
		int l=Tree[s][i];
		if(Hash[l]){
			Hash[l]=false; flag=true;
			int tmp=Dfs(l);
			if(tmp!=-1){
				Cost[s][l]=Min(tmp,Cost[s][l]);
			}
			Sum+=Cost[s][l];
		}
	}
	if(!flag) return -1;
	return Sum;
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n||m){
		if(n==1){
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++){
			Tree[i].clear();
		}
		memset(Hash,true,sizeof(Hash));
		Hash[m]=false;
		for(int i=1;i<n;i++){
			int p1,p2,cost;
			scanf("%d %d %d",&p1,&p2,&cost);
			Tree[p1].push_back(p2);
			Tree[p2].push_back(p1);
			Cost[p1][p2]=Cost[p2][p1]=cost;
		}
		int Ans=Dfs(m);
		printf("%d\n",Ans);
	}
}
