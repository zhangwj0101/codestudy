////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-23 15:13:35
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1437
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<stdio.h>
double w[1001][4];
main()
{
	int n,m,i,j,k,start,end,day;
	double p[4][4];
	for(scanf("%d",&n);n>0;n--)
	{
		for(i=1;i<=3;i++)
			for(j=1;j<=3;j++)
				scanf("%lf",&p[i][j]);
		for(scanf("%d",&m);m>0;m--)
		{
			scanf("%d%d%d",&start,&end,&day);
			for(i=0;i<=day;i++)
				w[i][1]=w[i][2]=w[i][3]=0;
			w[0][start]=1;
			for(i=0;i<day;i++)
			{
				w[i+1][1]=w[i][1]*p[1][1]+w[i][2]*p[2][1]+w[i][3]*p[3][1];
				w[i+1][2]=w[i][1]*p[1][2]+w[i][2]*p[2][2]+w[i][3]*p[3][2];
				w[i+1][3]=w[i][1]*p[1][3]+w[i][2]*p[2][3]+w[i][3]*p[3][3];
			}
			printf("%.3lf\n",w[day][end]);
		}
	}
}