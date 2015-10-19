////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-04 17:22:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2114
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<iostream>
using namespace std;

__int64 sum[10000];
void main()
{
    int n,i=2,j;sum[1]=1;
    while(scanf("%d",&n)!=EOF)
    {
        n=n%10000;
        for(;i<=n;i++)
        {
            sum[i]=sum[i-1]+(__int64)i*(__int64)i*(__int64)i;
            if(sum[i]>10000)
                sum[i]=sum[i]%10000;
        }
        printf("%04d\n",sum[n]);
    }
}