////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-22 16:56:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:796MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,i,j,num[20000],c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n+m;i++)
			scanf("%d",&num[i]);
		for(i=0;i<m+n-1;i++)
			for(j=i+1;j<m+n;j++)
				if(num[i]>num[j])
				{c=num[i];num[i]=num[j];num[j]=c;}
		printf("%d",num[0]);
		for(i=1;i<m+n;i++)
		{
			if(num[i]!=num[i-1])
				printf(" %d",num[i]);
		}
		printf("\n");
	}
}