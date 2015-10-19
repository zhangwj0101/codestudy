////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 12:57:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2149
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int step[1100];
main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        step[0]=0;
        for(i=1;i<=m;i++)
            step[i]=1;
        for(;i<=n;i++)
        {
            for(j=1;j<=m;j++)
				if(i>=j&&step[i-j]==0)
					break;
            if(j==m+1) step[i]=0;
            else step[i]=1;
        }
        if(step[n])
        {
            for(i=1;;i++)
                if(step[n-i]==0)
                {
                    printf("%d",i);
                    break;
                }
				for(i++;i<=(n>m?m:n);i++)
                if(step[n-i]==0)
                printf(" %d",i);
            for(;i<=m;i++)
                printf(" %d",i);
            printf("\n");
        }
        else printf("none\n");
    }
}