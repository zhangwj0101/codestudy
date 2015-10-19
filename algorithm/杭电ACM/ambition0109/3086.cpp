////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-12-06 21:33:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3086
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
// freopen("s.in","r",stdin);
int t ;
double s , ax , bx , ay , by , d , m , r1 , r2 ;
while( scanf( "%d",&t ) != EOF ) 
{
   while( t -- )
   {
    m = 0 ;
    scanf("%lf",&s ) ;
    scanf( "%lf %lf" , &ax , &bx ) ;
    scanf( "%lf %lf" , &ay , &by ) ;
    if( ay!=ax )
    {
     d = (by-bx)*(by-bx)+2*(ay-ax)*s ;
     if( d < 0 )
     {
      printf( "Good driver,Jiaoshou!\n" ) ;
      continue ;
     }
     r1 = (bx-by-sqrt(d))/(ay-ax) ;
     r2 = (bx-by+sqrt(d))/(ay-ax) ;
     if( r1 >= 0 && r2 >= 0 )
     {
      if( r1 < r2 )
       m = r1 ;
      else
       m = r2 ;
     }
     else if( r1 >= 0 && r2 < 0 )
      m = r1 ;
     else if( r2 >= 0 && r1 < 0 )
      m = r2 ;
     else
     {
      printf( "Good driver,Jiaoshou!\n" ) ;
      continue ;
     }
     printf( "Oh,God!Jiaoshou will be catched after %.3lf minutes.\n" , m ) ;
    }
    else
    {
    if( by != bx )      // 红色部分加上了才能过，细节上的
      m = s/(by-bx) ;
     else
      m = -1 ;
     if( m < 0 )
      printf( "Good driver,Jiaoshou!\n" ) ;
     else
      printf( "Oh,God!Jiaoshou will be catched after %.3lf minutes.\n" , m ) ;
    }
   }
}
return 0 ;
}