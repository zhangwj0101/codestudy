////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-06-13 11:30:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int mi(int n, int m)
{
    return m?(m%2?(mi(n, m/2)*mi(n, m/2)*(n%1000))%1000:(mi(n,m/2)*mi(n,m/2))%1000):1;
}

int main(void)
{
    int n, m;

    while(scanf("%d%d", &n, &m), n+m)
        printf("%d\n", mi(n, m));
    return 0;
}