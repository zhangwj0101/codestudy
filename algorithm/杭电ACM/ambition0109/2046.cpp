////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-16 21:16:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2046
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i;
	__int64 num[3];
	while(scanf("%d",&n)!=EOF)
	{
		for(num[0]=1,num[1]=1,i=0;i<n;i++)
		{
			num[2]=num[1];
			num[1]+=num[0];
			num[0]=num[2];
		}
		printf("%I64d\n",num[0]);
	}
}
