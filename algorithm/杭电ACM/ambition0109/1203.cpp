////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-20 13:02:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include<stdio.h>
double num[10001],v[1000];
int w[1000];
main()
{
	int n,m,i,j;
	while(scanf("%d%d",&m,&n),m||n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%lf",&w[i],&v[i]);
			v[i]=1.-v[i];
		}
		for(i=0;i<=m;i++)
			num[i]=1;
		for(i=0;i<n;i++)
		{
			for(j=m;j>=w[i];j--)
			{
				if(num[j-w[i]]*v[i]<num[j])
					num[j]=num[j-w[i]]*v[i];
			}
		}
		printf("%.1lf%%\n",100.*(1.-num[m]));
	}
}