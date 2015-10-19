////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 14:29:23
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int n,m,w;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
		n=n%10;m=m%4+3;
        for(w=n;m>0;m--)
        {
            w*=n;
            w=w%10;
        }
		printf("%d\n",w);
    }
}