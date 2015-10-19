////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-29 16:36:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{
    int tt,i,j,t,n,v,sum[100],w,con[100];
    for(scanf("%d",&tt);tt>0;tt--)
    {
        scanf("%d%d%d",&n,&v,&w);
        for(i=0;i<n;i++)scanf("%d",&con[i]);
		for(i=1;i<n;i++)
			  for(j=0;j<n-i;j++)
				if(con[j]>con[j+1])
				{t=con[j];con[j]=con[j+1];con[j+1]=t;}
        sum[0]=con[0];i=0;
        while(1.0*sum[i]/(i+1)<=w&&i<n)
        {sum[i+1]=sum[i]+con[i+1];i++;}
        if(i==0)
        printf("0 0.00\n");
        else
        printf("%d %.2lf\n",i*v,0.01*sum[i-1]/i);
    }
}