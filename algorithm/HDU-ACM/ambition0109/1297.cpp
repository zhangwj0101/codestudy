////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-08 16:17:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1297
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:4124KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int f[1001][1000];
int main()
{
    int n,i,k=1,j;
    for(i=0;i<1001;i++)
        for(j=0;j<1000;j++)
            f[i][j]=0;
    f[0][0]=f[1][0]=f[2][0]=f[3][0]=1;
    f[0][1]=1;f[1][1]=1;f[2][1]=2;f[3][1]=4;
    for(i=4;i<1001;i++)
    {
        for(j=1;j<=k;j++)
        {
            f[i][j]+=f[i-1][j]+f[i-2][j]+f[i-4][j];
            if(f[i][j]>9)
            {
                f[i][j+1]+=(f[i][j]/10);
				f[i][j]%=10;
            }
        }
        if(f[i][k+1]!=0) k++;
        f[i][0]=k;
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(i=f[n][0];i>0;i--)
            printf("%d",f[n][i]);
        printf("\n");
    }
    return 0;
}