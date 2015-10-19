////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-06 10:03:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,wage,count;
	while(scanf("%d",&n),n)
	{
		for(i=0,count=0;i<n;i++)
			for(scanf("%d",&wage);;)
				if(wage>=100)
					wage=wage-100,count++;
				else if(wage>=50)
					wage=wage-50,count++;
				else if(wage>=10)
					wage=wage-10,count++;
				else if(wage>=5)
					wage=wage-5,count++;
				else if(wage>=2)
					wage=wage-2,count++;
				else if(wage>=1)
					wage=wage-1,count++;
				else
					break;
		printf("%d\n",count);
	}
}