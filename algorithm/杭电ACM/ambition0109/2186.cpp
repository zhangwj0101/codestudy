////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: ambition0109
////Nickname: Ambition
////Run ID: 
////Submit time: 2010-02-18 12:36:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2186
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include<stdio.h>
main()
{
	int n,num,term,sum;
	for(scanf("%d",&n);n>0;n--)
	{
		scanf("%d",&num);
		sum=0;
		term=num/2;
		if(term%10)
			sum+=term/10+1;
		else
			sum+=term/10;
		num-=term;
		term=num*2/3;
		if(term%10)
			sum+=term/10+1;
		else
			sum+=term/10;
		term=num-term;
		if(term%10)
			sum+=term/10+1;
		else
			sum+=term/10;
		printf("%d\n",sum);
	}
}