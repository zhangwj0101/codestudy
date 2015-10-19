////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 15:36:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,cow[4],i;
	while(scanf("%d",&n),n)
	{
		cow[3]=1;
		for(i=0;i<3;i++)
			cow[i]=0;
		for(m=1;m<n;m++)
		{
			cow[3]+=cow[2];
			cow[2]=0;
			cow[2]+=cow[1];
			cow[1]=0;
			cow[1]+=cow[0];
			cow[0]=0;
			cow[0]+=cow[3];
		}
		printf("%d\n",cow[0]+cow[1]+cow[2]+cow[3]);
	}
}