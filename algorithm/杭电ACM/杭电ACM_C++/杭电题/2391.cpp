////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-10-03 09:27:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2391
////Problem Title: 
////Run result: Accept
////Run time:1171MS
////Run memory:3856KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;
#define M(a,b) a>b?a:b
int map[1001][1001];
int main()
{
	int t,i,k,n,m,j;
	cin>>t;
	for(k=1;k<=t;k++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&map[i][j]);
		for(j=1;j<m;j++)
			map[0][j]+=map[0][j-1];
		for(i=1;i<n;i++)
		{
			map[i][0]+=map[i-1][0];
			for(j=1;j<m;j++)
				map[i][j]+=M(map[i-1][j],map[i][j-1]);
		}
		printf("Scenario #%d:\n%d\n\n",k,map[n-1][m-1]);
	}
	return 0;
}