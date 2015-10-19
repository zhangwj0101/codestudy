////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-24 18:11:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1785
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cmath>
using namespace std;
struct point{double x,y,alpha;}p[101];
int main()
{
    int n,i,j,k;
    double x,y;
    while(cin>>n&&n>0)
    {
     for(i=0;i<n;i++)
     {
      cin>>x>>y;
      p[i].x=x;
      p[i].y=y;
      p[i].alpha=fabs(atan2(y,x));
     }
     for(i=0;i<n-1;i++)
      for(j=i+1;j<n;j++)
      {
       if(p[i].alpha>p[j].alpha)
       swap(p[i],p[j]);
      }
      for(k=i=0;i<n;i++)
      printf("%s%.1lf %.1lf",(k++?" ":""),p[i].x,p[i].y);
      puts("");
    }
    return 0;
}