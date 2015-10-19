////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-07 13:34:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1465
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int m,i;
	__int64 num[21];
	num[2]=1;num[3]=2;
	for(i=4;i<21;i++)
		num[i]=(i-1)*num[i-2]+(i-1)*num[i-1];
	while(scanf("%d",&m)!=EOF)
		printf("%I64d\n",num[m]);
}