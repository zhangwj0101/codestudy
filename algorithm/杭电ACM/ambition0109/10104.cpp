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
const int START = 10;  //���˾�֪��ɶ��˼ 
const int DOOR = 20;
const int WALL = 0;
const int ROAR = 1;
int N = 0,M = 0,T = 0; //����� 
int maze[11][11];      //���������Թ���ͼ 
int d[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
int f = 1,roarCount = 0;  //����Ƿ��ҵ�· , ��¼�����ߵ�·�ĸ��� 
int DFS ( int x,int y,int n )
{
	if ( n == T )     //ʱ��������, �ߵ�����û ? 
	{
		if ( x == END.x && y == END.y )
			f = 0;
		return 0;  
	}
	if ( f == 0 )     //�Ѿ��ҵ�·��, ��������  
		return 0;
	int t = T - n - abs( x-END.x ) - abs( y-END.y );  //��ż��֦ 
	if ( t < 0 || t % 2 == 1 )     //����ʱ���� �� �������ߵ� 
		return 0;  
	for ( int i = 0; i != 4; ++ i )
	{
		if ( maze[ x+d[i][0] ][ y+d[i][1] ] != WALL )    //�ȿ�����һ���ܲ����� 
		{
			maze[x+d[i][0]][y+d[i][1]] = WALL;    //�߹���Ͳ������� 
			DFS ( x+d[i][0], y+d[i][1], n + 1 );  //�ߵ���һ��λ�� 
			if ( f == 0 )     //�Ѿ��ҵ�·��, ��������  
				return 0; 
			maze[x+d[i][0]][y+d[i][1]] = ROAR;    //û�ҵ�·,������ 
		}
	} 
	return 0;
}
void init()  //��������һ��, �ѿ�, ��������, ������ 
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
		if ( roarCount >= T )      //��ȻҪ��֤���ߵ�·�ȿ��ŵ�ʱ��Ҫ�� 
		{
			maze[start.x][start.y] = WALL;
			DFS( start.x, start.y, 0 );
		}  
		puts ( f == 1 ? "NO" : "YES" );
	}
	return 0;
}
