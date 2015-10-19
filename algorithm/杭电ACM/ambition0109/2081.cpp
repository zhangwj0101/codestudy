////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-11 22:08:23
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i;
	char num[200][12];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%s",num[i]);
		for(i=0;i<n;i++)
		{
			printf("6");
			printf("%c%c%c%c%c\n",num[i][6],num[i][7],num[i][8],num[i][9],num[i][10]);
		}
	}
}