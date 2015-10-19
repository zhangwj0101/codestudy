////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-10 12:56:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int l,up,down,sum,n;
	while(scanf("%d%d%d",&l,&up,&down),l||up||down)
	{
		for(sum=0,n=0;sum<l;n++)
		{
			if(n)
			{
				sum-=down;
				n++;
			}
			sum+=up;
		}
		printf("%d\n",n);
	}
}