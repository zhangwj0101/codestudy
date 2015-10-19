////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 12:29:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2111
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
    int v,n,i,j,m[100],p[100],value;
    while(scanf("%d",&v),v)
    {
        for(scanf("%d",&n),i=0;i<n;i++)
            scanf("%d%d",&p[i],&m[i]);
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(p[j]>p[i])
                {
                    m[i]^=m[j];m[j]^=m[i];m[i]^=m[j];
                    p[i]^=p[j];p[j]^=p[i];p[i]^=p[j];
                }
        for(i=0,value=0;v-m[i]>=0&&i<n;i++)
        {
            v-=m[i];
            value+=m[i]*p[i];
        }
        if(v&&i!=n) value+=p[i]*v;
        printf("%d\n",value);
    }
}