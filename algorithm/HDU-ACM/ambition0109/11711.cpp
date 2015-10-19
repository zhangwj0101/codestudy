////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 13:26:50
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:796MS
////Run memory:460KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[300001],kk[51],w[51];
main()
{
	int n,m,i,j,k,sum;
	while(scanf("%d",&n),n>=0)
	{
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d%d",&w[i],&kk[i]);
			sum+=w[i]*kk[i];
		}
		m=sum/2;
		for(i=0;i<=m;i++)
			num[i]=0;
		for(i=0;i<n;i++)
		{
			for(k=0;k<kk[i];k++)
			for(j=m;j>=w[i];j--)
			{
				if(num[j-w[i]]+w[i]>num[j])
					num[j]=num[j-w[i]]+w[i];
			}
		}
		printf("%d %d\n",sum-num[m],num[m]);
	}
}