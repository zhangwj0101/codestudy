////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-03-20 12:07:13
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2568
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,num,b;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&num);
		for(b=0;num!=0;num/=2)
		{
			if(num%2)
			{num-=1;b++;}
		}
		printf("%d\n",b);
	}
}