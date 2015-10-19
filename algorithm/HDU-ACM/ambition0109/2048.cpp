////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-07 15:09:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i;
	__int64 num[21],fnum[21];
	double ans[21];
	num[2]=1;num[3]=2;
	fnum[2]=2;fnum[3]=6;
	ans[1]=0;
	ans[2]=1./2.;ans[3]=1./3.;
	for(i=4;i<21;i++)
	{
		num[i]=(i-1)*(num[i-2]+num[i-1]);
		fnum[i]=i*fnum[i-1];
		ans[i]=(double)num[i]/(double)fnum[i];
	}
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&m);
		printf("%.2lf%%\n",ans[m]*100);
	}
}