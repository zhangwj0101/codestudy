////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 00:16:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <iostream>
typedef unsigned long UL;
using namespace std;
UL lcm(UL a,UL b)            //求两个数最小公倍数的算法
{
    UL a1=a,b1=b,r;
    while(b1)                //先用辗转相除法求出a，b的最大公约数c， a*b/c就是a，b的最小公倍数
    {
        r=a1%b1;
        a1=b1;
        b1=r;
    }
    a1=a*b/a1;
    return a1;
}
int main()
{
    UL a,b,n;
   while(cin>>n)
   {
       a=1;
       while(n--)
       {
            cin>>b;
            a=lcm(a,b);
       }
       cout<<a<<endl;
   }
   return 0;
}