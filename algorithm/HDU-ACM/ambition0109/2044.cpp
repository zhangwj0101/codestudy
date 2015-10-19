////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-16 21:55:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2044
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m[2],c,i;
	__int64 num[3];
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&m[0],&m[1]);
		for(c=m[1]-m[0],num[0]=1,num[1]=1,i=0;i<c;i++)
		{
			num[2]=num[1];
			num[1]+=num[0];
			num[0]=num[2];
		}
		printf("%I64d\n",num[0]);
	}
}