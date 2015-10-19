////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-29 17:11:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3496
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:420KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<string>
#include<memory>
#include<sstream>
#include<algorithm>
using namespace std;

int v[105],w[105];
int bag[105][1005];
int main()
{
	memset(bag[0],0,sizeof(bag[0]));
	int t,n,m,av;cin>>t;
	while(t--){
		cin>>n>>m>>av;
		for(int k=1;k<=m;k++)
			for(int i=0;i<=av;i++)
				bag[k][i]=-1;
		for(int i=0;i<n;i++)
			cin>>w[i]>>v[i];
		for(int i=0;i<n;i++){
			for(int k=m;k>0;k--){
				for(int j=w[i];j<=av;j++){
					if(bag[k-1][j-w[i]]!=-1)
					if(bag[k][j]<bag[k-1][j-w[i]]+v[i])
						bag[k][j]=bag[k-1][j-w[i]]+v[i];
				}
			}
		}
		if(bag[m][av]==-1) cout<<0<<endl;
		else cout<<bag[m][av]<<endl;
	}
}