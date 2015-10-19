////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-10 11:41:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1425
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:4120KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int num[1000001];
main()
{
	int n,m,i,number;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<1000001;i++)
			num[i]=0;
		for(;n>0;n--)
		{
			scanf("%d",&number);
			num[number+500000]=1;
		}
		for(i=1000000;m>0;i--)
		{
			if(num[i])
			{
				printf("%d",i-500000);
				if(m>1)
					printf(" ");
				m--;
			}
		}
		printf("\n");
	}
}