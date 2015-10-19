////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-08 11:23:11
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2028
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,m,x,i,t,num[1000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		for(m=num[0],i=1;i<n;i++)
			m=(num[i]>m?num[i]:m);
		for(x=m;;x+=m)
		{
			for(i=0;i<n;i++)
				if((x%num[i]))
					break;
			if(i==n)
				break;
		}
		printf("%d\n",x);
	}
}