////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-13 22:53:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
//нртнак
int main()
{
    int n, m, i;

    while (scanf("%d%d", &m, &n), m+n)
    {
        for (i = 1; n/i-(i-1)/2>0; i++);
        for(i--; i && n/i+i/2 <= m; i--)
        {
            if((n-n/i*i)*2 == i)
                printf("[%d,%d]\n", n/i-(i-1)/2, n/i+i/2);
            if(!(n%i) && i%2)
                printf("[%d,%d]\n", n/i-(i-1)/2, n/i+i/2);
        }
        putchar('\n');
    }
    return 0;
}