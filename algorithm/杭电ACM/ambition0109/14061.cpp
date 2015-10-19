////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 10:16:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:288KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[10000],sign[10000];
main()
{
	int n,m1,m2,i,j;
	for(i=0;i<10000;i++)
	{num[i]=1;sign[i]=0;}
	for(i=2;i<10000;i++)
		for(j=2;j*i<10000;j++)
			num[i*j]+=i;
	for(i=2;i<10000;i++)
	{
		if(num[i]==i)
			sign[i]=1;
		sign[i]+=sign[i-1];
	}
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&m1,&m2);
		if(m1>m2)
			i=m1,m1=m2,m2=i;
		printf("%d\n",sign[m2]-sign[m1-1]);
	}
}