////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-02 20:47:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1188KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
#include<malloc.h>
char visit[1000];
char map[1000][1000];
int n;
void dfs(int index)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(map[index][i]&&!visit[i])
		{
			visit[i]=1;
			dfs(i);
		}
	}
}
void main()
{
	int m,i,c1,c2,k;
	while(scanf("%d",&n),n)
	{
		k=0;
		memset(visit,0,n);
		memset(map,0,1000000);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&c1,&c2);
			map[c1-1][c2-1]=1;
			map[c2-1][c1-1]=1;
		}
		for(i=0;i<n;i++)
		{
			if(!visit[i])
			{
				dfs(i);
				k++;
			}
		}
		printf("%d\n",k-1);
	}
}