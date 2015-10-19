////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-11 23:44:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2500
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
		for(scanf("%d",&m),i=0;i<m*3;i++)
		{
			for(j=0;j<m;j++)
				printf("HDU");
			printf("\n");
		}
	}
}