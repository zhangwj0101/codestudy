////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 13:14:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2501
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,m,i,num[3];
    for(scanf("%d",&n);n>0;n--)
    {
        for(scanf("%d",&m),num[0]=1,num[1]=1,i=0;i<m;i++)
        {
            num[2]=num[1]+2*num[0];
            num[0]=num[1];
            num[1]=num[2];
        }
        printf("%d\n",num[0]);
    }
}