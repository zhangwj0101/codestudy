////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-24 09:43:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    double a,b;
    int n,m;
    while(cin>>n,n)
    {
        a=n;
        a=a*(a+1)*(a+2)/6.;
        m=log10(a);
        b=a/pow(10.,m);
        printf("%.2lfE%d\n",b,m);
    }
    return 0;
}