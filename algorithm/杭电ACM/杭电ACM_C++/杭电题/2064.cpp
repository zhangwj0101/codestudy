////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-10 20:40:26
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    __int64 i,n,a[36]={0,2};
    while(scanf("%I64d",&n)!=EOF)
    {
        for(i=2;i<=n;i++)
            a[i]=a[i-1]*3+2;
        printf("%I64d\n",a[n]);
    }
}