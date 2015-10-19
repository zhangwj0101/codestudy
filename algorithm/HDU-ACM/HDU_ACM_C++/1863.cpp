////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2010-03-04 23:07:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
#define INF 1000000000

int m, n;
int mat[100][100];
bool v[100];

void dfs(int i)
{
	v[i] = true;
	for (int j = 0; j < n; j++)
		if (!v[j] && mat[i][j] != INF)
			dfs(j);
}

int Prim(int n)
{
	int min[100], ret = 0;
	int v[100], i, j, k;
	for (i = 0; i < n; i++)
		min[i] = INF, v[i] = 0;
	for (min[j = 0] = 0; j < n; j++)
	{
		for (k = -1, i = 0; i < n; i++)
			if (!v[i] && (k == -1 || min[i] < min[k]))
				k = i;
		for (v[k] = 1, ret += min[k], i = 0; i < n; i++)
			if (!v[i] && mat[k][i] < min[i])
				min[i] = mat[k][i];
	}
	return ret;
}

int main()
{
	int a, b, c, i, j;
	while (scanf("%d%d", &m, &n), m)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				mat[i][j] = INF;
		memset(v, false, sizeof(v));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			mat[a-1][b-1] = mat[b-1][a-1] = c;
		}
		int cnt = 0;
		for (i = 0; i < n; i++)
			if (!v[i])
				++cnt, dfs(i);
		if (cnt > 1) printf("?\n");
		else printf("%d\n", Prim(n));
	}
    return 0;
}

