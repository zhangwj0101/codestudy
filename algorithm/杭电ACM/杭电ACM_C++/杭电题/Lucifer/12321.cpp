////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-15 12:10:39
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:1188KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 1000
char mat[M][M];
char v[M];
int n;
void dfs(int vi)
{
	int i;
	v[vi]=1;
	for(i=0;i<n;i++)
	{
		if(!v[i]&&mat[vi][i])
		{
			dfs(i);
		}
	}
}
int main()
{
	int m;
	int a,b;
	int cnt;
	int i;
	while (scanf("%d",&n),n)
	{
		memset(mat,0,sizeof(mat));
		memset(v,0,n);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			mat[a-1][b-1]=mat[b-1][a-1]=1;
		}
		for(cnt=i=0;i<n;i++)
		{
			if(!v[i])
			{
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
