////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-04-28 16:48:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 3354
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,n1,n2,n3,o=1;
	while(scanf("%d",&n),n)
	{
		printf("%d. ",o++);
		n1=3*n;
		if(n1%2)
		{
			printf("odd ");
			n2=(n1+1)/2;
		}
		else
		{
			printf("even ");
			n2=n1/2;
		}
		n3=n2/3;
		printf("%d\n",n3);
	}
}