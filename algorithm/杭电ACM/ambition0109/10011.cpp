////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-13 17:55:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:152KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    unsigned int n;
    while((scanf("%u",&n))!=EOF)
    {
        printf("%u\n\n",n*(n+1)/2);
    }
}