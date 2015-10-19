////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-15 15:34:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,o=1;
	while(scanf("%d",&n),n>0)
	{
		if(n==1||n==2)
			printf("%d: no",o++);
		else
		{
			for(i=2;i<n;i++)
				if(!(n%i))
				{printf("%d: no",o++);break;}
			if(i==n)
				printf("%d: yes",o++);
		}
		printf("\n");
	}
}