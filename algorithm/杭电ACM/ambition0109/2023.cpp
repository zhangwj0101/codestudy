////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 17:51:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int n,m,i,j,member,k;
    double a[50][5],sum,ave[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
         for(j=0;j<m;j++)
             scanf("%lf",&a[i][j]);
         for(i=0;i<n-1;i++)
         {  sum=0;
           for(j=0;j<m;j++)
                sum+=a[i][j];
            sum=sum/m;
            printf("%.2lf ",sum);
         }
         sum=0;
         for(j=0;j<m;j++)
             sum+=a[i][j];sum=sum/m;
         printf("%.2lf\n",sum);
         for(j=0;j<m-1;j++)
         { sum=0;
         for(i=0;i<n;i++)
             sum+=a[i][j];
         sum=sum/n;ave[j]=sum;
         printf("%.2lf ",sum);
         }
         sum=0;
         for(i=0;i<n;i++)
             sum+=a[i][j];
         sum=sum/n;ave[j]=sum;
        printf("%.2lf\n",sum);
        member=0;
         for(i=0;i<n;i++)
         { k=0;
           for(j=0;j<m;j++)
               if(ave[j]>a[i][j]) k++;
            if(k==0) member++;
         }
         printf("%d\n\n",member);
    }
}