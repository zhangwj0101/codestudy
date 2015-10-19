////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-31 19:36:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2143
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    __int64 a,b,c;
    while(scanf("%I64d%I64d%I64d",&a,&b,&c)!=EOF)
    {
        if((a+b==c)||(c+b==a)||(a+c==b))
            printf("oh,lucky!\n");
        else if((a*b==c)||(c*b==a)||(a*c==b))
            printf("oh,lucky!\n");
        else if((b&&(a%b==c))||(a&&(b%a==c)))
            printf("oh,lucky!\n");
        else if((c&&(a%c==b))||(a&&(c%a==b)))
            printf("oh,lucky!\n");
        else if((b&&(c%b==a))||(c&&(b%c==a)))
            printf("oh,lucky!\n");
        else
            printf("what a pity!\n");
    }
}