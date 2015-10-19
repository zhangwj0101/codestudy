////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-16 16:28:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,a,b,i,j,t,count,max,num;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d%d",&a,&b);
		for(i=a,max=0;i<=b;i++)
		{
			for(j=1,count=0;j<=i;j++)
				if(!(i%j))
					count++;
			num=count;
			if(num>max)
			{max=num;t=i;}
		}
		printf("%d\n",t);
	}
}