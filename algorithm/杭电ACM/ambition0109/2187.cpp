////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-18 12:58:50
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2187
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,j,m,k,u[1000],w[1000],tmp;
	double allw;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&m,&k);
		for(i=0;i<k;i++)
			scanf("%d%d",&u[i],&w[i]);
		for(i=0;i<k-1;i++)
			for(j=i+1;j<k;j++)
				if(u[i]>u[j])
				{
					tmp=u[i];u[i]=u[j];u[j]=tmp;
					tmp=w[i];w[i]=w[j];w[j]=tmp;
				}
		for(i=0,allw=0;;i++)
			if(m<=w[i]*u[i])
			{
				allw+=(double)m/(double)u[i];
				break;
			}
			else
			{
				allw+=w[i];
				m-=u[i]*w[i];
			}
		printf("%.2lf\n",allw);
	}
}