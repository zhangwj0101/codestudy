////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 15:12:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2191
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int num[101],v[101],w[101],g[101];
main()
{
    int n,m,i,j,k,t;
    for(scanf("%d",&t);t>0;t--)
    {
		scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
            scanf("%d%d%d",&w[i],&v[i],&g[i]);
        for(i=0;i<=m;i++)
            num[i]=0;
        for(i=0;i<n;i++)
        {
			for(k=0;k<g[i];k++)
            for(j=m;j>=w[i];j--)
            {
                if(num[j-w[i]]+v[i]>num[j])
                    num[j]=num[j-w[i]]+v[i];
            }
        }
		printf("%d\n",num[m]);
    }
}