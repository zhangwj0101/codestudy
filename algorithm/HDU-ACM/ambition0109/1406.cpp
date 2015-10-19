////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-01 15:15:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,s,e,ss,ee,num[5]={1,6,28,496,8128};
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&s,&e);
		if(s>e)
			i=s,s=e,e=i;
		for(i=0;i<5;i++)
			if(s<=num[i])
				break;
		ss=i-1;
		for(i=0;i<5;i++)
			if(e<num[i])
				break;
		ee=i-1;
		printf("%d\n",ee-ss);
	}
}