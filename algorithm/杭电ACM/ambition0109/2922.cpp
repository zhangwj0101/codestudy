////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-25 17:51:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2922
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,num[11][11],i,j;
	for(i=0;i<11;i++)
	{num[i][0]=1;num[0][i]=1;}
	for(i=1;i<11;i++)
		for(j=1;j<11;j++)
			num[i][j]=num[i-1][j]+num[i][j-1];
	while(scanf("%d%d",&n,&m),n+1||m+1)
	{
		printf("%d+%d",n,m);
		if(n+m!=num[n][m])
			printf("!");
		printf("=%d\n",n+m);
	}
}