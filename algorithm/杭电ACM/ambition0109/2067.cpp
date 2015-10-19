////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-19 10:17:50
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	__int64 num[37];
	int n,t,i,j;
	num[0]=num[1]=1;
	for(i=2;i<37;i++)
	{
		num[i]=0;
		for(j=0;j<i;j++)
			num[i]+=num[i-j-1]*num[j];
	}
	t=1;
	while(scanf("%d",&n),n!=-1)
	{
		printf("%d %d %I64d\n",t++,n,num[n]*2);
	}
}