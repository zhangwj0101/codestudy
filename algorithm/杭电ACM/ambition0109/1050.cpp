////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 13:48:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int a[200];
void main()
{
    int t,n,i,j,x,y,k,h,m;
    scanf("%d",&t);
    for(j=0;j<t;j++)
    {
        for(i=0;i<200;i++)
            a[i]=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            x=(x-1)/2;
            y=(y-1)/2;
            if(x>y)
            {
                k=x;
                x=y;
                y=k;
            }
            for(h=x;h<=y;h++)
                a[h]+=1;
        }
        m=a[0];
        for(i=0;i<200;i++)
        {
            if(m<a[i])
                m=a[i];
        }
        printf("%d\n",10*m);
    }
}