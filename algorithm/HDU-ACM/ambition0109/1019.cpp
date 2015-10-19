////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-18 16:06:06
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int a[10000],n,i,t,m,j;
	scanf("%d",&j);
	for(;j>0;j--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(t=a[0],i=1;i<n;i++)
			if(a[i]>t)
				t=a[i];
		for(m=t;;m+=t)
		{
			for(i=0;i<n;i++)
				if(m%a[i]!=0)
					break;
			if(i==n)
				break;
		}
		printf("%d\n",m);
	}
}