////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: devil_momo
////Nickname: Lucifer
////Run ID: 
////Submit time: 2008-09-10 00:24:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2095
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:0KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int t,a,sum;
    while(scanf("%d",&t) && t!=0)
    {
        scanf("%d",&sum);
        t-=1;
        while(t--)
        {
			scanf("%d",&a);
			sum^=a;
        }
        printf("%d\n",sum);
    }
    return 0;
}