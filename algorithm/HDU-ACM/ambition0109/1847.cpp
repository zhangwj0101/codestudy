////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-05-05 10:18:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1847
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int step[1001];
main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		step[0]=0;
		for(i=1;i<=n;i*=2)
			step[i]=1;
		for(i=1;i<=n;i++)
		{
			if(step[i]==0)
			{
				for(j=1;j<i;j*=2)
					if(step[i-j]==0)
						break;
				if(j>=i)
					step[i]=0;
				else
					step[i]=1;
			}
		}
		if(step[n])
			printf("Kiki\n");
		else
			printf("Cici\n");
	}
}