////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-14 12:09:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3729
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:744KB
//////////////////System Comment End//////////////////
/*
 * 3729.cpp
 *
 *  Created on: 2010-12-14
 *      Author: hduacm
 */

#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define M 100005

int gra[100][2];
int mat[M];
bool Hash[M];

bool Find(int t){
	//printf("# %d\n",t);
	for(int v=gra[t][0];v<=gra[t][1];v++){
		//printf("## %d\n",v);
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

int Edmonds(int N){
	int cnt=0;
	memset(mat,-1,sizeof(mat));
	for(int i=N-1;i>=0;i--){
		memset(Hash,true,sizeof(Hash));
		if(Find(i)) cnt++;
	}
	return cnt;
}

vector<int> Ans;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,Min=100000,Max=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&gra[i][0],&gra[i][1]);
			if(gra[i][0]<Min) Min=gra[i][0];
			if(gra[i][1]>Max) Max=gra[i][1];
		}

		int cnt=Edmonds(n);//puts("*");
		Ans.clear();
		for(int i=Min;i<=Max;i++){
			if(mat[i]!=-1){
				Ans.push_back(mat[i]+1);
			}
		}
		sort(Ans.begin(),Ans.end());
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++){
			if(i) printf(" ");
			printf("%d",Ans[i]);
		}
		puts("");
	}
}
