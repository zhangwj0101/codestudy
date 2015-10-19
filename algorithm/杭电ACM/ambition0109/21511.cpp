////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 14:23:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2151
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int tree[100][100];
main()
{
	int n,p,m,t,i,j;
	while(scanf("%d%d%d%d",&n,&p,&m,&t)!=EOF)
	{
		for(i=0;i<=m;i++)
			for(j=1;j<=n;j++)
				tree[i][j]=0;
		tree[0][p]=1;
		for(i=0;i<m;i++)
		{
			if(tree[i][1])
				tree[i+1][2]+=tree[i][1];
			for(j=2;j<n;j++)
				if(tree[i][j])
				{
					tree[i+1][j-1]+=tree[i][j];
					tree[i+1][j+1]+=tree[i][j];
				}
			if(tree[i][n])
				tree[i+1][n-1]+=tree[i][n];
		}
		printf("%d\n",tree[m][t]);
	}
}