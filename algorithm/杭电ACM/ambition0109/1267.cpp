////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 13:10:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1267
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
__int64 num[21][21];
main()
{
	int n,m,i,j,k;
	for(i=0;i<21;i++)
		num[i][0]=1;
	for(i=1;i<21;i++)
		for(j=1;j<=i;j++)
			num[i][j]=num[i-1][j]+num[i][j-1];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%I64d\n",num[n][m]);
	}
}