////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-30 11:22:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1712
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:376KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

int bag[101][101],value[101][101];
void main()
{
	int n,m;
	while(cin>>n>>m,n||m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>value[i][j];
				bag[i][j]=value[i][j];
				if(bag[i][j]<bag[i][j-1])
					bag[i][j]=bag[i][j-1];
			}
		for(int i=2;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(bag[i][j]<bag[i-1][j])
						bag[i][j]=bag[i-1][j];
				for(int k=1;k<=j;k++)
					if(bag[i][j]<bag[i-1][j-k]+value[i][k])
						bag[i][j]=bag[i-1][j-k]+value[i][k];
				if(bag[i][j]<bag[i][j-1])
					bag[i][j]=bag[i][j-1];
			}
		cout<<bag[n][m]<<endl;	
	}
}