////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-20 12:40:09
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:424KB
//////////////////System Comment End//////////////////
#include <stdio.h>    //给定小范围内素数可以用枚举解决，快很多
#include <math.h>
int sushu(int a);
int place(int x[],int k);
int prime[12]={2,3,5,7,11,13,17,19,23,29,31,37};
int place(int x[],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(x[i]==x[k]||(sushu(x[k]+x[k-1])==0))
            return 0;
    }
    return 1;
}
int sushu(int a)
{
    int i;
   
    for(i=0;i<=11;i++)
    {
        if(a==prime[i])
        {
            return 1;
        }
    }
    return 0;
}
int a[200000][50],n;
int x[100000];
int main()
{
   
    int i,j,k,d,s,c=0;
   
    while(scanf("%d",&n)!=EOF)
    {
        k=1;
        x[1]=0;
        s=1;
        //搜索部分
        while(k>0)
        {
            x[k]=x[k]+1;
            while(x[k]<=n&&(!place(x,k)))
            {
                x[k]=x[k]+1;
            }
            if(x[k]<=n)
            {
                if(k==n)
                {
                    if(x[1]!=1)
                            break;
                    if(sushu(x[n]+x[1])==1)
                    {
                        for(d=1;d<=n;d++)
                        {
                            a[s][d]=x[d];
                           
                        }
                        s++;
                   
                    }
                }else
                {
                    k=k+1;x[k]=0;
                }
            }else
            {
                x[k]=0;k=k-1;
            }
       
        }
        //搜索部分
        printf("Case %d:\n",++c);
        for(i=1;i<s;i++)
        {
            for(j=1;j<=n;j++)
            {
              if(j==1)
              {
                printf("%d",a[i][j]);
              }else
              {
                  printf(" %d",a[i][j]);
              }
            }
            printf("\n");
           
           
        }
        printf("\n");
       
    }
}