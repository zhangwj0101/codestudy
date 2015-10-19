////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 11:52:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1978
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int n,m;
int map[101][101];
int dfs[101][101];
int DFS(int x,int y)
{
	int count=0,power=map[x][y];
	for(int i=0;i<=power&&x+i<=n;i++){
		for(int j=0;i+j<=power&&y+j<=m;j++){
			if(i+j>0){
				if(dfs[x+i][y+j]==-1)
					dfs[x+i][y+j]=DFS(x+i,y+j);
				count+=dfs[x+i][y+j];
				count%=10000;
			}
		}
	}
	return count;
}

void main()
{
	int t;
	for(cin>>t;t--;)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>map[i][j];
				dfs[i][j]=-1;
			}
		dfs[n][m]=1;
		dfs[1][1]=DFS(1,1);
		cout<<dfs[1][1]<<endl;
	}
}