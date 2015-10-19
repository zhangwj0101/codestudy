////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-08-01 10:24:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<cmath>
using namespace std;
void main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<34)
        printf("%I64d\n",(__int64)pow(3.,(double)n)-1);
        else if(n==34)
            printf("16677181699666568\n");
        else if(n==35)
            printf("50031545098999706\n");
    }
}