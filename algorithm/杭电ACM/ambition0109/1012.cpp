////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 16:23:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void main()
{
    int i;
    double e,k;
    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    k=0.5;
    e=2.5;
    for(i=3;i<10;i++)
    {
        printf("%d ",i);
            k=k/i;
            e+=k;
        printf("%.9lf\n",e);
    }
}