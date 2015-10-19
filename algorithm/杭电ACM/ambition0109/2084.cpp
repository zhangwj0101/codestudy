////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-23 21:07:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,num[100][100];
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),i=0;i<m;i++)
			for(j=0;j<i+1;j++)
				scanf("%d",&num[i][j]);
		for(i=m-1;i>0;i--)
			for(j=0;j<i;j++)
				num[i-1][j]+=num[i][j]>num[i][j+1]?num[i][j]:num[i][j+1];
		printf("%d\n",num[0][0]);
	}
}