////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-25 19:10:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2415
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:444KB
//////////////////System Comment End//////////////////
/*
 * 2415.cpp
 *
 *  Created on: 2010-9-24
 *      Author: administrator
 */

#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int n,m;
int dp[210][210];
int val[210];
map<string,int> Hash;
vector<int> Map[210];
bool Node[210];

int Min(int a,int b){
	int dif=(b-a);
	return a+(dif&(dif>>31));
}

void Dfs(int t)
{
	int Size=Map[t].size();
	dp[t][0]=0;
	for(int i=0;i<Size;i++){
		Dfs(Map[t][i]);
		for(int j=n;j>=1;j--){
			for(int k=1;k<=j;k++){
				if(dp[t][j-k]==-1) continue;
				if(dp[Map[t][i]][k]==-1) continue;
				if(dp[t][j]==-1) dp[t][j]=dp[t][j-k]+dp[Map[t][i]][k];
				else dp[t][j]=Min(dp[t][j],dp[t][j-k]+dp[Map[t][i]][k]);
			}
		}
	}
	if(t!=0){
		for(int i=n;i>0;i--){
			if(dp[t][i-1]!=-1){
				dp[t][i]=val[t];
				break;
			}
		}
	}
}

int main()
{
	string str,name;
	while(cin>>str){
		if(str=="#") break;
		n=str[0]-'0';
		for(int i=1;i<int(str.length());i++){
			n*=10;
			n+=str[i]-'0';
		}
		cin>>m;
		val[0]=0;
		Hash.clear();
		memset(Node,true,sizeof(Node));
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<=n;i++){
			Map[i].clear();
		}
		for(int i=1,k=1;i<=n;i++){
			int value;
			cin>>name>>value;
			if(!Hash[name]) Hash[name]=k++;
			int ph=Hash[name];
			val[ph]=value;
			while(cin.get()==' '){
				cin>>name;
				if(!Hash[name]) Hash[name]=k++;
				int lh=Hash[name];
				Map[ph].push_back(lh);
				Node[lh]=false;
			}
		}
		for(int i=1;i<=n;i++){
			if(Node[i]){
				Map[0].push_back(i);
			}
		}
		Dfs(0);
		int min=dp[0][m];
		for(int i=m+1;i<=n;i++){
			if(dp[0][i]<min){
				min=dp[0][i];
			}
		}
		cout<<min<<endl;
	}
}
