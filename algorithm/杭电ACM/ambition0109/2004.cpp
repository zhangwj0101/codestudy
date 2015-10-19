////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-04 12:22:10
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
		if(a<0)
			printf("Score is error!\n");
		else if(a<=59)
			printf("E\n");
		else if(a<=69)
			printf("D\n");
		else if(a<=79)
			printf("C\n");
		else if(a<=89)
			printf("B\n");
		else if(a<=100)
			printf("A\n");
		else
			printf("Score is error!\n");
	}
}