////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-09 17:35:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1878
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:1196KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define M 1000
char v[M];
char mat[M][M];
int degree[M];
int n;
void dfs(int vi)
{
	int i;
	v[vi]=1;
	for (i=0;i<n;i++)
		if (!v[i]&&mat[vi][i])
			dfs(i);
	
}
int judge()
{
	int i;
	for (i=0;i<n;i++)
		if (degree[i]&1)
			return 0;

	return 1;

}
void main()
{
	int m;
	int a,b,cnt,i;
	while (scanf("%d",&n),n)
	{
		scanf("%d",&m);
		memset(mat,0,sizeof(mat));
		memset(v,0,n);
		memset(degree,0,sizeof(degree));
		cnt=0;
		while (m--)
		{
			scanf("%d%d",&a,&b);
			mat[a-1][b-1]=mat[b-1][a-1]=1;
			degree[a-1]++;
			degree[b-1]++;
		}
		for (i=0;i<n;i++)
			if (!v[i])
				cnt++,dfs(i);

		puts(cnt<=1&&judge()?"1":"0");
	}
	
}