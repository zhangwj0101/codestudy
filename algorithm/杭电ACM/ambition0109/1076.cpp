////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-01-31 12:57:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int y,year,id,i,n,add;
	for(scanf("%d",&id);id>0;id--)
	{
		scanf("%d%d",&y,&n);
		for(add=1,i=0,year=y;;year+=add)	
		{
			if((!(year%4)&&(year%100))||!(year%400))
			{
				add=4;
				i++;
				if(i==n)
					break;
			}
		}
		printf("%d\n",year);
	}
}
