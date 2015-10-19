////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-04-27 10:27:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double x1,x2,y1,y2,s;
   while(cin>>x1>>y1>>x2>>y2)
   {
       s=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        printf("%.2f\n",sqrt(s));
   }
   return 0;
}