////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-21 17:30:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2502
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
main()
{
	int n,num;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&num);
		printf("%d\n",(int)pow(2,num-2)*(num-1)+(int)pow(2,num-1));
	}
}