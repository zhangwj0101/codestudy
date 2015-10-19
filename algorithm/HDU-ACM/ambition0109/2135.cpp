////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-23 18:48:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2135
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j;
	char num[11][11];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		m%=4;if(m<0) m+=4;
		if(m==0)
		{
			for(i=0;i<n;i++)
				for(getchar(),j=0;j<n;j++)
					scanf("%c",&num[i][j]);
		}
		else if(m==3)
		{
				for(j=0;j<n;j++)
					for(getchar(),i=n-1;i>=0;i--)
					scanf("%c",&num[i][j]);
		}
		else if(m==2)
		{
			for(i=n-1;i>=0;i--)
				for(getchar(),j=n-1;j>=0;j--)
					scanf("%c",&num[i][j]);
		}
		else if(m==1)
		{
			for(i=n-1;i>=0;i--)
				for(getchar(),j=0;j<n;j++)
					scanf("%c",&num[j][i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%c",num[i][j]);
			printf("\n");
		}
	}
}