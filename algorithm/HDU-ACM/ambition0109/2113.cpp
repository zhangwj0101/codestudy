////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-18 14:49:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2113
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int num,i=0,m,sum[1000];
	while(scanf("%d",&num)!=EOF)
	{
		for(sum[i]=0;num>0;num/=10)
		{
			if((num%10)%2==0)
				sum[i]+=num%10;
		}
		i++;
	}
	m=i;
	printf("%d\n",sum[0]);
	for(i=1;i<m;i++)
		printf("\n%d\n",sum[i]);
}