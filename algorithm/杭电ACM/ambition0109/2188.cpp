////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 13:00:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2188
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int step[10000];
main()
{
    int t,n,m,i,j;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d%d",&n,&m);
        step[0]=0;
        for(i=1;i<=m;i++)
            step[i]=1;
        for(i=m+1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
                if(step[i-j]==0)
                    break;
            if(j==m+1)
                step[i]=0;
            else
                step[i]=1;
        }
        if(step[n])
            printf("Grass\n");
        else
            printf("Rabbit\n");
    }
}