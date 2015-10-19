////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-13 21:41:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include <math.h>
#include <stdio.h>

int main(void)
{
    int n;
    double h, m, s;

    scanf("%d", &n);
    while (n-- && scanf("%lf%lf%lf", &h, &m, &s))
    {
        if (h > 12) h -= 12;
        printf("%d\n", (h=fabs(30*h-11*m/2-11*s/120))>180?(int)(360-h):(int)h);
    }
    return 0;
}