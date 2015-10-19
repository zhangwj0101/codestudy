////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-25 16:54:55
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1421
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:8024KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int fatige[2000][1000];
main()
{
	int n,m,i,j,t,num[2000];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(num[i]>num[j])
					t=num[i],num[i]=num[j],num[j]=t;
		fatige[1][0]=(num[1]-num[0])*(num[1]-num[0]);
		for(i=2;i<n;i++)
			for(j=0;j<(i+1)/2;j++)
			{
				if((i+1)==(j+1)*2)
					fatige[i][j]=(num[i]-num[i-1])*(num[i]-num[i-1])+fatige[i-2][j-1];
				else
				{
					if(j)
						t=(num[i]-num[i-1])*(num[i]-num[i-1])+fatige[i-2][j-1];
					else
						t=(num[i]-num[i-1])*(num[i]-num[i-1]);
					fatige[i][j]=fatige[i-1][j]>t?t:fatige[i-1][j];
				}
			}
		printf("%d\n",fatige[n-1][m-1]);
	}
}
