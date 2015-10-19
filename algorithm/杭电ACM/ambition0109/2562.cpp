////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-11 23:05:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2562
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i;
	char num[51],tmp;
	for(scanf("%d",&n),getchar();n>0;n--)
	{
		scanf("%s",num);
		for(i=0;num[i]!='\0';i+=2)
				tmp=num[i],num[i]=num[i+1],num[i+1]=tmp;
		printf("%s\n",num);
	}
}