////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-06-28 11:21:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2710
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main ()
{
    int i,j,n,m,max,maxi;
    int a[20050]={0};
    for (i=2;i<20050;i++)
    {
           if (a[i]==0)
           for(j=1;j*i<20050;j++)
            a[i*j]=i;
    }
    while (scanf("%d",&n)!=EOF)
    {
       max=0;maxi=1;
       while (n--)
       {
            scanf("%d",&m);
            if (a[m]>max)
            {
               maxi=m;
                 max=a[m];
            }
        }
       printf ("%d\n",maxi);
    }
return 0;
}