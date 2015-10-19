////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-07-09 21:10:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1397
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:24KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#define MAX 32768
int b[MAX]={0};
int main()
{
    int a, i, j;
    b[2] = 1;
    for(i=3; i<MAX; i += 2)
        b[i] = 1;
    for(i=2; i<MAX; i++)
    {
        if(b[i])
        {
            for(j = 1; j < MAX/i; j++)
            {
                b[i + j * i] = 0;
            }
        }
    }
    while(scanf("%d", &a))
    {
        int n = 0, k = a/2;
        if(a == 0)
            break;
        for(i=3; i<=k; i+=2)
        {
            if(b[i] && b[a-i])
                n++;
        }
        printf("%d\n", n);
    }
    return 0;
}