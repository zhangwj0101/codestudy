////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 15:55:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
void bubble(int a[],int n)
{
    int i,t,j;
    for(i=1;i<n;i++)
    for(j=0;j<n-i;j++)
    if(a[j]>a[j+1])
    {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
    }
}
int main()
{
    int t,ri,i,j,n,v,sum[100],w,p[100];
    scanf("%d",&t);
    for(ri=1;ri<=t;ri++)
    {
        scanf("%d%d%d",&n,&v,&w);
        for(i=0;i<n;i++)
        scanf("%d",&p[i]);
        bubble(p,n);
        sum[0]=p[0];
        j=0;
        while(1.0*sum[j]/(j+1)<=w&&j<n)
        {
            sum[j+1]=sum[j]+p[j+1];
            j++;
        }
        if(j==0)
        printf("0 0.00\n");
        else
        printf("%d %.2lf\n",j*v,0.01*sum[j-1]/j);
    }
}