////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-07 15:00:13
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,k,t,j[1001],f[1001];
	double v[1001],ans,value;
	while(scanf("%d%d",&m,&n),m+1||n+1)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&j[i],&f[i]);
			v[i]=(double)j[i]/(double)f[i];
		}
		for(i=0,value=0;i<n;i++)
		{
			for(k=i+1;k<n;k++)
				if(v[i]<v[k])
				{
					ans=v[i];v[i]=v[k];v[k]=ans;
					t=j[i];j[i]=j[k];j[k]=t;
					t=f[i];f[i]=f[k];f[k]=t;
				}
			if(m>=f[i])
			{
				value+=(double)j[i];
				m-=f[i];
			}
			else
			{
				value+=(double)j[i]/(double)f[i]*(double)m;
				break;
			}
		}
		printf("%.3lf\n",value);
	}
}