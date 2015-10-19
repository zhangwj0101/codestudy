////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-07 10:58:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1978
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:1076KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int n,m,power;
int map[101][101];
int dfs[101][101][20];
int DFS(int x,int y,int power)
{
	int count=0;
	for(int i=0;i<=power&&x+i<=n;i++){
		for(int j=0;i+j<=power&&y+j<=m;j++){
			if(i+j>0){
				if(dfs[x+i][y+j][map[x+i][y+j]]==-1)
					dfs[x+i][y+j][map[x+i][y+j]]=DFS(x+i,y+j,map[x+i][y+j])%10000;
				count+=dfs[x+i][y+j][map[x+i][y+j]];
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
			for(int j=1;j<=m;j++)
			{
				cin>>map[i][j];
				for(int k=0;k<20;k++)
					dfs[i][j][k]=-1;
			}
		power=map[1][1];
		for(int i=0;i<20;i++) dfs[n][m][i]=1;
		dfs[1][1][map[1][1]]=DFS(1,1,map[1][1])%10000;
		cout<<dfs[1][1][map[1][1]]<<endl;
	}
}