////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 17:28:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2519
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[31][31]={0};
main()
{
    int n,i,j,x,y;
	for(i=0;i<31;i++)
		num[i][0]=num[i][i]=1;
	for(i=2;i<31;i++)
		for(j=1;j<i;j++)
			num[i][j]=num[i-1][j]+num[i-1][j-1];
    for(scanf("%d",&n);n>0;n--)
    {
		scanf("%d%d",&x,&y);
		printf("%d\n",num[x][y]);
    }
}