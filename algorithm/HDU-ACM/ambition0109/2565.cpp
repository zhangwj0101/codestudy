////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 12:42:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2565
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		for(i=0;i<m/2;i++)
		{
			for(j=0;j<i;j++)
				printf(" ");
			printf("X");
			for(j=m-2*i-2;j>0;j--)
				printf(" ");
			printf("X\n");
		}
		for(j=0;j<i;j++)
			printf(" ");
		printf("X\n");
		for(i=0;i<m/2;i++)
		{
			for(j=m/2-1;j>i;j--)
				printf(" ");
			printf("X");
			for(j=1;j<i*2+2;j++)
				printf(" ");
			printf("X\n");
		}
		printf("\n");
	}
}