////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-27 15:31:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2549
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
main()
{
    int n,i,m,t;
    char dec[100];
    for(scanf("%d",&n);n>0;n--)
    {
        scanf("%d.%s %d",&m,dec,&t);
        if(t<=strlen(dec))
            printf("%c\n",dec[t-1]);
        else
            printf("0\n");
    }
}