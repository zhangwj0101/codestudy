////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-07-09 22:38:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2515
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:188KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int a[1250],ans[51];
int main()
{
    int n,nn,i,j,all,part,ds,dt,f,t;
    while(scanf("%d",&n)!=EOF)
    {
        nn=n*(n-1)/2; all=0;
        for(i=0;i<nn;i++)
        {
            scanf("%d",&a[i]);
            all+=a[i];
        }
        all/=(n-1);
        part=0; dt=ds=n-2; f=0;
        for(i=0;i<nn-1;i++)
        {
            part+=a[i];
            if(i==ds)
            {
                ans[f]=(part-all)/(n-f-2);
                all-=ans[f];
                ds+=(dt-f);
                f++;
                part=0;
            }
        }
        ans[f]=a[nn-3]-ans[f-1];ans[f+1]=a[nn-2]-ans[f-1];
        for(i=0;i<f+1;i++)
            for(j=i+1;j<f+2;j++)
                if(ans[i]>ans[j]) t=ans[i],ans[i]=ans[j],ans[j]=t;
        for(i=0;i<f+2;i++)
            printf("%d\n",ans[i]);
    }
}