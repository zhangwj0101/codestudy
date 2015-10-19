////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-18 09:23:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:180KB
//////////////////System Comment End//////////////////
/*
Author By : MiYu
Test      : 1
Program   : HDU1010
*/

#include <iostream>
using namespace std;
typedef struct pos{
	int x,y;
	void setPos( int a = 0,int b = 0 ){ x = a; y = b; }
}POS; 
POS start,END;
const int START = 10;  //看了就知道啥意思 
const int DOOR = 20;
const int WALL = 0;
const int ROAR = 1;
int N = 0,M = 0,T = 0; //输入的 
int maze[11][11];      //很明显是迷宫地图 
int d[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int f = 1,roarCount = 0;  //标记是否找到路 , 记录可以走的路的个数 
int DFS ( int x,int y,int n )
{
	if ( n == T )     //时间用完了, 走到出口没 ? 
	{
		if ( x == END.x && y == END.y )
			f = 0;
		return 0;  
	}
	if ( f == 0 )     //已经找到路了, 不用找了  
		return 0;
	int t = T - n - abs( x-END.x ) - abs( y-END.y );  //奇偶剪枝 
	if ( t < 0 || t % 2 == 1 )     //不够时间了 或 不可能走到 
		return 0;  
	for ( int i = 0; i != 4; ++ i )
	{
		if ( maze[ x+d[i][0] ][ y+d[i][1] ] != WALL )    //先看看下一步能不能走 
		{
			maze[x+d[i][0]][y+d[i][1]] = WALL;    //走过后就不能走了 
			DFS ( x+d[i][0], y+d[i][1], n + 1 );  //走到下一个位置 
			if ( f == 0 )     //已经找到路了, 不用找了  
				return 0; 
			maze[x+d[i][0]][y+d[i][1]] = ROAR;    //没找到路,回溯下 
		}
	} 
	return 0;
}
void init()  //在主函数一堆, 难看, 放外面了, 不解释 
{
	memset ( maze, 0, sizeof ( maze ) );
	f = 1, roarCount = 0;
	for ( int i = 1; i <= N; ++ i )
	{
		char ch[20];
		scanf ("%s", ch+1 );
		for ( int j = 1; ch[j] && !isspace(ch[j]) ; ++ j )
		{
			switch ( ch[j] )
			{
			case 'S':  maze[i][j] = START; start.setPos ( i,j ); break;
			case '.':  maze[i][j] = ROAR;  roarCount ++; break;
			case 'X':  maze[i][j] = WALL;  break;              
			case 'D':  maze[i][j] = DOOR;  END.setPos ( i,j ); roarCount ++; break;
			}
		} 
	}      
}
int main ()
{
	while ( scanf ( "%d%d%d",&N, &M, &T ), N + M + T )
	{
		init ();
		if ( roarCount >= T )      //当然要保证能走的路比开门的时间要多 
		{
			maze[start.x][start.y] = WALL;
			DFS( start.x, start.y, 0 );
		}  
		puts ( f == 1 ? "NO" : "YES" );
	}
	return 0;
}
