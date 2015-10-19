////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 16:46:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2955
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include<stdio.h>
double money[10001],w[101];
int v[101];
main()
{
    int n,i,j,t,sum;
	double max;
    for(scanf("%d",&t);t>0;t--)
    {
		scanf("%lf%d",&max,&n);
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d%lf",&v[i],&w[i]);
			sum+=v[i];w[i]=1.-w[i];
		}
		for(i=0;i<=sum;i++)
			money[i]=-1;
		money[0]=1;
		for(i=0;i<n;i++)
		{
			for(j=sum;j>=v[i];j--)
			{
				if(money[j-v[i]]!=-1)
				{
					if(money[j-v[i]]*w[i]>money[j])
						money[j]=money[j-v[i]]*w[i];
				}
			}
		}
		for(i=sum;i>=0;i--)
			if(money[i]!=-1.0&&money[i]>=(1.-max))
				break;
		printf("%d\n",i);
    }
}