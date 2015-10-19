////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2009-12-30 18:31:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1262
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:180KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,i,x,num;
	while(scanf("%d",&num)!=EOF)
	{
		for(n=num/2;n>0;n--)
		{
			x=1;
			for(i=n-1;i>1;i--)
				if(!(n%i))
				{
					x=0;
					break;
				}
			if(x)
				for(i=num-n-1;i>1;i--)
					if(!((num-n)%i))
					{
						x=0;
						break;
					}
			if(x)
				break;
		}
		printf("%d %d\n",n,num-n);
	}
}