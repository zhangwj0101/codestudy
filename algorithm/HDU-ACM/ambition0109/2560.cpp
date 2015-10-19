////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 11:08:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2560
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,x,y,num,count,i;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&x,&y);
		for(i=0,count=0;i<x*y;i++)
		{
			scanf("%d",&num);
			if(num)
				count++;
		}
		printf("%d\n",count);
	}
}