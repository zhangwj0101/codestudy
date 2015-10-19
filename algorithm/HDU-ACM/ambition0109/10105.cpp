////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-09-13 18:34:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:256KB
//////////////////System Comment End//////////////////
# include <stdio.h>
# include <memory.h>
# define ABS(x) ((x) < 0 ? ((-1) * (x)) : (x))

char g[10][10] ;
int flag[10][10] ;
int dp[10][10][100] ;

int startx, starty, endx, endy ;
int N, M, T, WALL;


int dfs (int x, int y, int t, int wall)
{
	//合法性
	if (x >= N || x < 0 || y < 0 || y >= M || g[x][y] == 'X')
		return 0 ; 
	//奇偶
	if ((x ^ y ^ endx ^ endy ^ t) & 1) return 0 ;

	//最短路
	if (ABS (x - endx) + ABS (y - endy) > t) return 0 ;
	
	//路径
	if ((N * M - wall) <= t) return 0 ;
	
	//记忆化1
	//if (dp[x][y][t] == 1) return 0 ; 
	
	//成功
	if (t == 0 && g[x][y] == 'D') return 1 ;
	
	int xx[4] = {-1, 0, 1, 0}, yy[4] = {0, -1, 0, 1} ;
	char buf ;
	for (int i = 0 ; i < 4 ; i++)
	{
		buf = g[x][y] ;
		g[x][y] = 'X' ;
		if (dfs (x + xx[i], y + yy[i], t - 1, wall + 1) == 1) return 1 ;
		g[x][y] = buf ;
	}
	//记忆化2 
	//dp[x][y][t] = 1 ;
	return 0 ;
}



int main ()
{
	int i, j ;
	while (1)
	{
		scanf ("%d%d%d", &N, &M, &T) ;
		if (N == 0 && M == 0 && T == 0) break ;
		
		getchar () ;
		WALL = 0 ;
		for (i = 0 ; i < N ; i++)
		{
			for (j = 0 ; j < M  ;j++)
			{
				scanf ("%c", &g[i][j]) ;
				if (g[i][j] == 'S')
				{
					startx = i ;
					starty = j ;
					flag[i][j] = 1 ;
				}
				if (g[i][j] == 'D')
				{
					endx = i ;
					endy = j ;
				}
				if (g[i][j] == 'X') WALL ++ ;
			}
			getchar () ;
		}
		memset (flag, 0, sizeof (flag)) ;
		memset (dp, 0, sizeof (dp)) ;
		printf ("%s\n", dfs (startx, starty, T, WALL) ? "YES" : "NO") ;
	}
	return 0 ;
}