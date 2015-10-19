////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 10:49:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1286
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:336KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<math.h>
int num[32768];
main()
{
	int n,m,i,j,count;
	for(scanf("%d",&n);n>0;n--)
	{
		for(scanf("%d",&m),i=0;i<m;i++) num[i]=0;
		for(i=2;i<=m/2;i++)
			if(m%i==0)	num[i]=1;
		for(i=2;i<=m/2;i++)
		{
			if(num[i])
				for(j=2;i*j<m;j++)
					num[i*j]=1;
		}
		for(i=1,count=0;i<m;i++)
			if(!num[i]) count++;
		printf("%d\n",count);
	}
}