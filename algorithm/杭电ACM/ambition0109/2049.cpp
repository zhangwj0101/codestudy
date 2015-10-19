////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-07 15:35:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,t;
	__int64 num[21],fnum[21];
	fnum[1]=1;fnum[2]=2;
	num[1]=0;num[2]=1;
	for(i=3;i<21;i++)
	{
		fnum[i]=i*fnum[i-1];
		num[i]=(i-1)*(num[i-2]+num[i-1]);
	}
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&m,&t);
		if(m!=t)	printf("%I64d\n",fnum[m]/fnum[t]/fnum[m-t]*num[t]);
		else	printf("%I64d\n",num[t]);
	}
}