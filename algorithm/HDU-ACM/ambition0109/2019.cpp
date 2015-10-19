////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 15:51:31
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,x,num[101];
	while(scanf("%d%d",&n,&m),m||n)
	{
		for(i=0,x=1;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(num[i]>=m&&x)
			{
				num[i+1]=num[i];
				num[i]=m;
				i++,n++,x=0;
			}
		}
		if(x)
		{num[i]=m;n++;}
		printf("%d",num[0]);
		for(i=1;i<n;i++)
			printf(" %d",num[i]);
		printf("\n");
	}
}