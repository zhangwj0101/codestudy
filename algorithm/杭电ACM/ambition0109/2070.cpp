////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-21 12:50:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i;
	__int64 num[3];
	while(scanf("%d",&n),n+1)
	{
		for(i=0,num[0]=0,num[1]=1;i<n;i++)
		{
			num[2]=num[0]+num[1];
			num[0]=num[1];
			num[1]=num[2];
		}
		printf("%I64d\n",num[0]);
	}
}