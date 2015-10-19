////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 17:55:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2105
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
using namespace std;
int main()
{
    double x,y,xs,ys;
    int i,n;
    while(cin>>n&&n)
    {
     while(n--)
     {
      for(xs=ys=i=0;i<3;i++)
      {
       cin>>x>>y;
       xs+=x;
       ys+=y;
      }
      printf("%.1lf %.1lf\n",xs/3,ys/3);
     }
    }
    return 0;
}