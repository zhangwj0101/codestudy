////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 17:45:13
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include"stdio.h"
int main()
{
    char str[100][100];
    int i,j,n,m,sub=0;
    char lu,su,d;
    while(scanf("%d %c %c",&n,&lu,&su)!=EOF)
    {
        if(sub==1)
            printf("\n");
        m=n;
        for(i=1;i<=(n+1)/2;i++)
        {
            if(m%4==1)
                d=lu;
            else
                d=su;
            for(j=i;j<=n-i+1;j++)
            {
                    str[i][j]=d;
                    str[j][i]=d;
                    str[j][n-i+1]=d;
                    str[n-i+1][j]=d;
            }
            m+=2;
        }
        if(n!=1)
        str[1][1]=str[1][n]=str[n][1]=str[n][n]=' ';
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                    printf("%c",str[i][j]);
                printf("\n");
            }
        sub=1;
    }
        return 0;
    }