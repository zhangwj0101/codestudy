////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-05 14:48:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int m,n,i,j,num[101],sum;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<101;i++)
			num[i]=0;
		for(i=1;i<=n;i++)
			num[i]=num[i-1]+2;
		for(i=1;;i+=m)
		{
			for(j=0,sum=0;j<m;j++)
			{
				sum+=num[i+j];
				if(!num[i+j])
					break;
			}
			if(j)
			{
				printf("%d",sum/j);
				if(num[i+m])
					printf(" ");
			}
			else
			{
				printf("\n");
				break;
			}
		}
	}
}