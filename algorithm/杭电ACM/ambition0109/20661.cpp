////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-15 10:52:09
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:4248KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
const int INF = 0x7FFFFFFF;
int T,S,D,L;
const int MAXN=1005;    //µã¸öÊý
int graph[MAXN][MAXN];
int s[MAXN];
int d[MAXN];
int Dijkstra ( int beg, int end )
{
    bool hash[MAXN];
    int path[MAXN];
    for ( int i = 0; i <= L; ++ i )
    {
          hash[i] = true;
          path[i] = INF; 
    } 
    hash[beg] = false;
    path[beg] = 0;
    while ( beg != end )
    {
           for ( int i = 0; i <= L; ++ i )
           {
                 if ( graph[beg][i] != -1 )
                 {
                      if ( path[i] > path[beg] + graph[beg][i] ) 
                           path[i] = path[beg] + graph[beg][i];
                 } 
           } 
           int min = INF;
           for ( int i = 0; i <= L; ++ i )
           {
                 if ( min > path[i] && hash[i] )
                 {
                      min = path[i];
                      beg = i; 
                 } 
           }
           hash[beg] = false;
    }   
    return path[end];
}

int main ()
{ 
    while ( scanf ( "%d%d%d",&T,&S,&D ) != EOF )
    {
          memset ( graph , -1 , sizeof ( graph ) );
          L = 0;
          for ( int i = 1; i <= T; ++ i )
          {
                int r,c,cost;
                scanf ( "%d%d%d",&r,&c,&cost );
                if ( graph[r][c] == -1 )
                     graph[r][c] = graph[c][r] = cost ;
                else
                {
                     if ( cost < graph[r][c] ) 
                          graph[r][c] = graph[c][r] = cost ;
                }
                if ( L < max ( r,c ) )
                     L = max ( r,c );
          } 
          for ( int i = 0; i != S; ++ i )
          {
               scanf ( "%d",&s[i] );
               graph[0][ s[i] ] = 0; 
               graph[ s[i] ][0] = 0;     
          }
          L ++;
          for ( int i = 0; i != D; ++ i )
          {
               scanf ( "%d",&d[i] );
               graph[ d[i] ][ L ] = 0;
               graph[ L ][ d[i] ] = 0;
          }
          
          cout << Dijkstra ( 0,L ) << endl;  
    }
    return 0; 
}