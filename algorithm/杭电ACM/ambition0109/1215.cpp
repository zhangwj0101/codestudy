////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 11:02:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2164KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[500001];
main()
{
	int n,m,i=1,j;
	for(i=0;i<500001;i++) num[i]=1;
	for(i=2;i<250001;i++)
	{
		for(j=2;i*j<500001;j++)
			num[i*j]+=i;
	}
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		printf("%d\n",num[m]);
	}
}