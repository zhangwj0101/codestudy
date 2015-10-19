////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 15:45:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2148
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,t,i,num[1000],count;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d%d",&m,&t),i=0;i<m;i++)
			scanf("%d",&num[i]);
		for(i=0,count=0;i<m;i++)
			if(num[i]>num[t-1])
				count++;
		printf("%d\n",count);
	}
}